#pragma once

#include <memory>
#include <SFML\Graphics.hpp>
#include "GameTime.hpp"
#include "States\GameStateManager.hpp"
#include "Log\LogManager.hpp"
#include "Input\InputManager.hpp"

class GameStateManager;
class InputManager;

class Game
{

private:

	// variables

	GameTime m_time;

	sf::RenderWindow m_window;
	sf::Event m_event;
	sf::Clock m_clock;

	unsigned int m_frameRate;
	float m_timePerFrame;
	float m_timeSinceLastUpdate;

	bool m_fixedTimeStep;
	bool m_handleWindowClose;

	sf::Color m_backgroundColor;

	std::unique_ptr<GameStateManager> m_statesManager;
	std::unique_ptr<LogManager> m_logManager;
	std::unique_ptr<InputManager> m_inputManager;

	bool m_stopRequested = false;

	// functions

	void startGameLoop();
	void handleWindowEvents();
	void handleUpdateDraw();

	void handleEvent(sf::Event const & event);
	void handleUpdate(GameTime const & time);
	void handleDraw(sf::RenderWindow & window);

protected:

	// Called if a event needs to process.
	virtual void onEvent(sf::Event const & event);

	// Called when an update is required.
	virtual void onUpdate(GameTime const time);

	// Called when a refresh is required.
	virtual void onDraw(sf::RenderWindow & window);

	// Called when the game should stop.
	// If false is returned, the stop process is canceled.
	virtual bool onStop();

public:

	// constructor

	Game();
	Game(std::string windowTitle, unsigned int windowWidth, unsigned int windowHeight);

	// deconstructor

	~Game();

	// public functions

	void start();
	void stop();

	sf::RenderWindow & getWindow();

	void enableFixedTimeStep(bool enabled);
	bool isFixedTimeStepEnabled() const;

	void enableAutoHandleClose(bool enabled);
	bool isAutoHandleCloseEnabled() const;

	void setBackgroundColor(sf::Color color);
	sf::Color getBackgroundColor() const;

	void setFrameRate(unsigned int framesPerSecond);
	unsigned int getFrameRate() const;

	GameStateManager & getStateManager() const;
	LogManager & getLogManager() const;
	InputManager & getInputManager() const;

	bool isStopRequested() const;

};
