#pragma once

#include <array>
#include "InputManager.hpp"

class InputManager;

class InputManagerKeyboard
{

private:

	friend class InputManager;

	std::array<bool, sf::Keyboard::KeyCount> m_state;
	std::array<bool, sf::Keyboard::KeyCount> m_previousState;

	void refreshState(std::array<bool, sf::Keyboard::KeyCount> & state);

	void onUpdate(GameTime time);

public:

	bool isKeyDown(sf::Keyboard::Key key);
	bool isKeyUp(sf::Keyboard::Key key);

	bool isKeyPressed(sf::Keyboard::Key key);
	bool isKeyReleased(sf::Keyboard::Key key);

};
