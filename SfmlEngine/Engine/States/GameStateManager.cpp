#include "GameStateManager.hpp"

GameState * GameStateManager::findStateByName(std::string name)
{
	for (GameState * state : m_states)
	{
		if (state->m_name == name)
			return state;
	}

	return nullptr;
}

bool GameStateManager::isStateActivate(GameState * state)
{
	for (GameState * state : m_activeStates)
	{
		if (state == state)
			return true;
	}

	return false;
}

void GameStateManager::handleStatesToActivate()
{
	// add a states to the list of active states
	while (!m_statesToActivate.empty())
	{
		GameState * stateToActivate = m_statesToActivate.front();
		m_statesToActivate.pop();

		if (!isStateActivate(stateToActivate))
		{
			if (!stateToActivate->m_loaded)
			{
				stateToActivate->m_loaded = true;
				stateToActivate->onLoad();
			}

			stateToActivate->onActivate();

			m_activeStates.push_back(stateToActivate);
		}
	}
}

void GameStateManager::handleStatesToDeactivate()
{
	// remove a state from the list of active states
	while (!m_statesToDeactivate.empty())
	{
		GameState * stateToDeactivate = m_statesToDeactivate.front();
		m_statesToDeactivate.pop();

		for (size_t i = 0; i < m_activeStates.size(); i++)
		{
			if (m_activeStates[i] == stateToDeactivate)
			{
				stateToDeactivate->onInactivate();

				m_activeStates.erase(m_activeStates.begin() + i);
			}
		}
	}
}

void GameStateManager::onEvent(sf::Event const & event)
{
	for (GameState * state : m_activeStates)
	{
		state->onEvent(event);
	}
}

void GameStateManager::onUpdate(GameTime const time)
{
	handleStatesToDeactivate();
	handleStatesToActivate();

	for (GameState * state : m_activeStates)
	{
		state->onUpdate(time);
	}
}

void GameStateManager::onDraw(sf::RenderWindow & window)
{
	for (GameState * state : m_activeStates)
	{
		state->onDraw(window);
	}
}

void GameStateManager::onStop()
{
	// call onInactivate for all activate states
	for (GameState * state : m_activeStates)
	{
		state->onInactivate();
	}

	// call onUnload for all loaded states
	for (GameState * state : m_states)
	{
		if (state->m_loaded)
			state->onUnload();
	}
}

GameStateManager::GameStateManager()
{
	m_states.reserve(100);
	m_activeStates.reserve(25);
}

GameStateManager::~GameStateManager()
{
}

bool GameStateManager::push(std::string name)
{
	GameState * stateToActivate = findStateByName(name);
	if (stateToActivate != nullptr)
	{
		m_statesToActivate.push(stateToActivate);
		return true;
	}

	return false;
}

bool GameStateManager::switchTo(std::string name)
{
	GameState * stateToActivate = findStateByName(name);
	if (stateToActivate == nullptr) // state not found
		return false;

	// push all activate states to the list of states to disable
	for (auto it = m_activeStates.rbegin(); it != m_activeStates.rend(); it++)
	{
		m_statesToDeactivate.push(*it);
	}

	m_statesToActivate.push(stateToActivate);
	return true;
}

bool GameStateManager::pop()
{
	// remove the last state from the activate states list, if any is active
	if (!m_activeStates.empty())
	{
		m_statesToDeactivate.push(m_activeStates.back());
	}

	return false;
}

bool GameStateManager::add(GameState & state, bool activate)
{
	// check if the state is not added already
	std::vector<GameState *>::iterator it = std::find(m_states.begin(), m_states.end(), &state);
	if (it == m_states.end())
	{
		// state not found. add them
		state.m_manager = this;
		m_states.push_back(&state);

		if (activate)
			m_statesToActivate.push(&state);

		return true;
	}

	// state is already added
	return false;
}

bool GameStateManager::remove(std::string name)
{
	return false;
}

Game & GameStateManager::getGame() const
{
	return *m_game;
}

sf::RenderWindow & GameStateManager::getWindow() const
{
	return m_game->getWindow();
}
