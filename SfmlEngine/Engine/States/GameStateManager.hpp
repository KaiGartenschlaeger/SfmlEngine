#pragma once

#include <vector>
#include <queue>

#include "..\Game.hpp"
#include "..\States\GameState.hpp"

class Game;
class GameState;

class GameStateManager
{

private:

	friend class Game;

	// variables

	Game * m_game;

	std::vector<GameState *> m_states;

	std::queue<GameState *> m_statesToActivate;
	std::queue<GameState *> m_statesToDeactivate;
	std::vector<GameState *> m_activeStates;

	// functions

	GameState * findStateByName(std::string name);
	bool isStateActivate(GameState * state);

	void handleStatesToActivate();
	void handleStatesToDeactivate();

	void onEvent(sf::Event const & event);
	void onUpdate(GameTime const time);
	void onDraw(sf::RenderWindow & window);
	void onStop();

public:

	GameStateManager();
	~GameStateManager();

	// Sets the state to the top state. 
	// If the state is already active, nothing is happen.
	bool push(std::string name);

	// Changes the current state to the given state.
	// All other activate states will be removed.
	bool switchTo(std::string name);

	// Inactivates the top state.
	// If no state is active, nothing is happen.
	bool pop();

	// Adds the state to the list of possible states.
	bool add(GameState & state, bool activate = false);

	// Removes the state from the list of possible states.
	// If the state is active, the state is automatically inactivated.
	bool remove(std::string name);

	Game & getGame() const;
	sf::RenderWindow & getWindow() const;

};
