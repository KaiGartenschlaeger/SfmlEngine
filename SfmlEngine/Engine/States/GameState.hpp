#pragma once

#include "..\Game.hpp"
#include "..\GameTime.hpp"
#include "..\States\GameStateManager.hpp"
#include "..\Input\InputManager.hpp"

class Game;
class InputManager;

class GameState
{

private:

	friend class GameStateManager;

	// variables

	bool m_loaded;
	std::string m_name;

	GameStateManager * m_manager;

public:

	GameState(std::string name);
	~GameState();

protected:

	virtual void onLoad();
	virtual void onActivate();

	virtual void onEvent(sf::Event const & event) = 0;
	virtual void onUpdate(GameTime const time) = 0;
	virtual void onDraw(sf::RenderWindow & window) = 0;

	virtual void onInactivate();
	virtual void onUnload();

	GameStateManager & getManager() const;
	Game & getGame() const;
	InputManager & getInputManager() const;
	sf::RenderWindow & getWindow() const;

};
