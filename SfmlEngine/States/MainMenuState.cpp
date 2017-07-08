#include "MainMenuState.h"

MainMenuState::MainMenuState()
	: GameState("MainMenu")
{
	std::cout << "MainMenuState ctor\n";
}

MainMenuState::~MainMenuState()
{
	std::cout << "MainMenuState dctor\n";
}

void MainMenuState::initText(sf::Text & textObj, std::string stringToSet, float posX, float posY)
{
	textObj.setFont(m_font);
	textObj.setCharacterSize(28);
	textObj.setString(stringToSet);
	textObj.setFillColor(sf::Color::White);
	textObj.setOutlineThickness(2);
	textObj.setOutlineColor(sf::Color::Black);
	textObj.setPosition(posX, posY);
}

void MainMenuState::refreshSelectedEntryColor()
{
	std::cout << "MainMenu refreshSelectedEntryColor, selectedEntry = " + std::to_string(m_selectedEntry) + "\n";

	m_startGame.setFillColor(InactiveEntryColor);
	m_exit.setFillColor(InactiveEntryColor);

	switch (m_selectedEntry)
	{
		case 0: m_startGame.setFillColor(ActiveEntryColor);
			break;
		case 1: m_exit.setFillColor(ActiveEntryColor);
			break;
	}
}

void MainMenuState::onLoad()
{
	std::cout << "MainMenuState onLoad\n";

	m_font.loadFromFile("Content/arial.ttf");

	sf::Vector2f viewSize = getWindow().getView().getSize();

	initText(m_startGame, "Spiel starten", 120, 100);
	initText(m_exit, "Beenden", 120, 150);

	m_backgroundTexture.loadFromFile("Content/mainMenuBg.png");

	sf::Vector2f viewportSize = getWindow().getView().getSize();
	sf::Vector2u textureSize = m_backgroundTexture.getSize();
	
	float scaleX = viewportSize.x / textureSize.x;
	float scaleY = viewportSize.y / textureSize.y;

	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setScale(scaleX, scaleY);
}

void MainMenuState::onUnload()
{
	std::cout << "MainMenuState onUnload\n";
}

void MainMenuState::onActivate()
{
	std::cout << "MainMenuState onActivate\n";

	getGame().setBackgroundColor(sf::Color(40, 40, 40));
	refreshSelectedEntryColor();
}

void MainMenuState::onInactivate()
{
	std::cout << "MainMenuState onInactivate\n";
}

void MainMenuState::onEvent(sf::Event const & event)
{
	if (event.type == sf::Event::EventType::KeyReleased)
	{
		switch (event.key.code)
		{
			case sf::Keyboard::Key::Escape:
				getGame().stop();
				break;

			case sf::Keyboard::Key::Up:
			case sf::Keyboard::Key::Left:
				m_selectedEntry--;
				if (m_selectedEntry < 0)
					m_selectedEntry = MaxSelectedEntry;
				refreshSelectedEntryColor();
				break;

			case sf::Keyboard::Key::Right:
			case sf::Keyboard::Key::Down:
				m_selectedEntry++;
				if (m_selectedEntry > MaxSelectedEntry)
					m_selectedEntry = 0;
				refreshSelectedEntryColor();
				break;

			case sf::Keyboard::Key::Return:
				switch (m_selectedEntry)
				{
					case 0: getManager().switchTo("Ingame");
						break;
					case 1: getGame().stop();
						break;
				}
				break;
		}
	}
}

void MainMenuState::onUpdate(GameTime const time)
{
	
}

void MainMenuState::onDraw(sf::RenderWindow & window)
{
	window.draw(m_backgroundSprite);
	window.draw(m_startGame);
	window.draw(m_exit);
}
