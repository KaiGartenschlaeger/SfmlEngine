#include "InputManager.hpp"

// constructor

InputManager::InputManager()
	: m_keyboard(new InputManagerKeyboard())
{
}

// deconstructor

InputManager::~InputManager()
{
}

// private functions

void InputManager::onUpdate(GameTime const time)
{
	m_keyboard->onUpdate(time);
}

// public functions

InputManagerKeyboard & InputManager::keyboard()
{
	return *m_keyboard;
}
