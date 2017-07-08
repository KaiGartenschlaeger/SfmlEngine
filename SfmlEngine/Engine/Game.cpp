#include "Game.hpp"

// game loop functions

void Game::handleWindowEvents()
{
	while (m_window.pollEvent(m_event))
	{
		if (m_handleWindowClose && m_event.type == sf::Event::EventType::Closed)
		{
			stop();
		}
		else
		{
			handleEvent(m_event);
		}
	}
}

void Game::handleUpdateDraw()
{
	if (m_stopRequested) // never call onUpdate or onDraw after stop has been called
		return;

	float elapsedFrameTime = m_clock.restart().asSeconds();
	m_clock.restart();

	if (m_fixedTimeStep)
	{
		bool executeDraw = false;

		m_timeSinceLastUpdate += elapsedFrameTime;
		while (m_timeSinceLastUpdate >= m_timePerFrame)
		{
			m_time.delta = m_timePerFrame;
			m_time.total += m_timePerFrame;

			handleUpdate(m_time);
			executeDraw = true;

			m_timeSinceLastUpdate -= m_timePerFrame;
		}

		if (executeDraw)
			handleDraw(m_window);
	}
	else
	{
		m_time.delta = elapsedFrameTime;
		m_time.total += m_time.delta;

		handleUpdate(m_time);
		handleDraw(m_window);
	}
}

void Game::handleEvent(sf::Event const & event)
{
	if (m_stopRequested) // never call onEvent after stop has been called
		return;

	onEvent(event);
	m_statesManager->onEvent(event);
}

void Game::handleUpdate(GameTime const & time)
{
	if (m_stopRequested) // never call onUpdate after stop has been called
		return;

	onUpdate(time);

	m_statesManager->onUpdate(time);
	m_inputManager->onUpdate(time);
}

void Game::handleDraw(sf::RenderWindow & window)
{
	if (m_stopRequested) // never call onDraw after stop has been called
		return;

	m_window.clear(m_backgroundColor);

	onDraw(window);
	m_statesManager->onDraw(window);

	m_window.display();
}

void Game::startGameLoop()
{
	// do first update/draw before the loop is starting
	handleWindowEvents();

	m_time.total = m_clock.getElapsedTime().asSeconds();
	m_time.delta = 0.0f;

	handleUpdate(m_time);
	handleDraw(m_window);

	// run loop until the window is closed
	while (m_window.isOpen())
	{
		handleWindowEvents();
		handleUpdateDraw();
	}
}

// constructor

Game::Game()
	: Game("SFML Window", 800, 600)
{
}

Game::Game(std::string windowTitle, unsigned int windowWidth, unsigned int windowHeight)
	:
	m_fixedTimeStep(true),
	m_frameRate(60),
	m_timePerFrame(1.0f / 60),
	m_timeSinceLastUpdate(0.0f),
	m_handleWindowClose(false),
	m_backgroundColor(0, 0, 0, 255),
	m_statesManager(new GameStateManager()),
	m_logManager(new LogManager()),
	m_inputManager(new InputManager())
{
	m_window.create(sf::VideoMode(windowWidth, windowHeight), windowTitle,
		sf::Style::Close | sf::Style::Titlebar);

	m_statesManager->m_game = this;
}

// deconstructor

Game::~Game()
{
	m_statesManager;
}

// events
// possible to override

void Game::onEvent(sf::Event const & event)
{
}

void Game::onUpdate(GameTime const time)
{
}

void Game::onDraw(sf::RenderWindow & window)
{
}

bool Game::onStop()
{
	return true;
}

// public functions

void Game::start()
{
	startGameLoop();
}

void Game::stop()
{
	if (m_stopRequested)
		return;

	if (onStop())
	{
		m_stopRequested = true;

		m_statesManager->onStop();

		m_window.close();
	}
}

sf::RenderWindow & Game::getWindow()
{
	return m_window;
}

void Game::enableFixedTimeStep(bool enabled)
{
	m_fixedTimeStep = enabled;
}

bool Game::isFixedTimeStepEnabled() const
{
	return m_fixedTimeStep;
}

void Game::enableAutoHandleClose(bool enabled)
{
	m_handleWindowClose = enabled;
}

bool Game::isAutoHandleCloseEnabled() const
{
	return m_handleWindowClose;
}

void Game::setBackgroundColor(sf::Color color)
{
	m_backgroundColor = color;
}

sf::Color Game::getBackgroundColor() const
{
	return m_backgroundColor;
}

void Game::setFrameRate(unsigned int framesPerSecond)
{
	m_frameRate = framesPerSecond;
	m_timePerFrame = 1.0f / framesPerSecond;
}

unsigned int Game::getFrameRate() const
{
	return m_frameRate;
}

GameStateManager & Game::getStateManager() const
{
	return *m_statesManager;
}

LogManager & Game::getLogManager() const
{
	return *m_logManager;
}

InputManager & Game::getInputManager() const
{
	return *m_inputManager;
}

bool Game::isStopRequested() const
{
	return m_stopRequested;
}
