#include "GameState.hpp"

GameState::GameState(std::string name)
	: m_name(name), m_loaded(false)
{
}

GameState::~GameState()
{
}

void GameState::onLoad()
{
}

void GameState::onActivate()
{
}

void GameState::onInactivate()
{
}

void GameState::onUnload()
{
}

GameStateManager & GameState::getManager() const
{
	return *m_manager;
}

Game & GameState::getGame() const
{
	return m_manager->getGame();
}

InputManager & GameState::getInputManager() const
{
	return getGame().getInputManager();
}

sf::RenderWindow & GameState::getWindow() const
{
	return getGame().getWindow();
}
