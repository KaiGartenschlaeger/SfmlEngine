#pragma once

#include <memory>
#include "..\Game.hpp"
#include "InputManagerKeyboard.hpp"

class Game;
class InputManagerKeyboard;

class InputManager
{

private:

	friend class Game;

	std::unique_ptr<InputManagerKeyboard> m_keyboard;

	void onUpdate(GameTime const time);

public:

	InputManager();
	~InputManager();

	InputManagerKeyboard & keyboard();

};
