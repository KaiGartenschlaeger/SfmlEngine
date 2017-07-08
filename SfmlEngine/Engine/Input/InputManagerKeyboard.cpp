#include "InputManagerKeyboard.hpp"

// private functions

void InputManagerKeyboard::refreshState(std::array<bool, sf::Keyboard::KeyCount>& state)
{
	for (size_t i = 0; i < state.size(); i++)
	{
		state[i] = sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i));
	}
}

void InputManagerKeyboard::onUpdate(GameTime time)
{
	m_previousState = m_state;
	refreshState(m_state);
}

// public functions

bool InputManagerKeyboard::isKeyDown(sf::Keyboard::Key key)
{
	return m_state[key];
}

bool InputManagerKeyboard::isKeyUp(sf::Keyboard::Key key)
{
	return !m_state[key];
}

bool InputManagerKeyboard::isKeyPressed(sf::Keyboard::Key key)
{
	return !m_previousState[key] && m_state[key];
}

bool InputManagerKeyboard::isKeyReleased(sf::Keyboard::Key key)
{
	return m_previousState[key] && !m_state[key];
}
