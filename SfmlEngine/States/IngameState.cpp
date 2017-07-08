#include "IngameState.h"

IngameState::IngameState()
	: GameState("Ingame")
{
	std::cout << "IngameState ctor\n";
}

IngameState::~IngameState()
{
	std::cout << "IngameState dctor\n";
}

void IngameState::onLoad()
{
	std::cout << "IngameState onLoad\n";

	m_charTexture.loadFromFile("Content/char_rope.png");

	m_charAnim.setTexture(m_charTexture);

	// down
	TiledSpriteAnimation walkDown(9, 4);
	walkDown.setSprite(m_charAnim);
	walkDown.addFrame(0, 2);
	walkDown.addFrame(1, 2);
	walkDown.addFrame(2, 2);
	walkDown.addFrame(3, 2);
	walkDown.addFrame(4, 2);
	walkDown.addFrame(5, 2);
	walkDown.addFrame(6, 2);
	walkDown.addFrame(7, 2);
	walkDown.addFrame(8, 2);

	m_charAnim.addAnimation(walkDown, "walkDown");

	// up
	TiledSpriteAnimation walkUp(9, 4);
	walkUp.setSprite(m_charAnim);
	walkDown.addFrame(0, 0);
	walkDown.addFrame(1, 0);
	walkDown.addFrame(2, 0);
	walkDown.addFrame(3, 0);
	walkDown.addFrame(4, 0);
	walkDown.addFrame(5, 0);
	walkDown.addFrame(6, 0);
	walkDown.addFrame(7, 0);
	walkDown.addFrame(8, 0);

	m_charAnim.addAnimation(walkUp, "walkUp");

	m_charAnim.setAnimation("walkDown");

}

void IngameState::onUnload()
{
	std::cout << "IngameState onUnload\n";
}

void IngameState::onActivate()
{
	std::cout << "IngameState onActivate\n";

	getGame().setBackgroundColor(sf::Colors::CornflowerBlue);
}

void IngameState::onInactivate()
{
	std::cout << "IngameState onInactivate\n";
}

void IngameState::onEvent(sf::Event const & event)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Key::Escape)
		getManager().switchTo("MainMenu");
}

void IngameState::onUpdate(GameTime const time)
{
	m_charAnim.update(time);

	if (getInputManager().keyboard().isKeyDown(sf::Keyboard::Key::Left))
	{
		m_charAnim.move(-1, 0);
	}
	else if (getInputManager().keyboard().isKeyDown(sf::Keyboard::Key::Right))
	{
		m_charAnim.move(1, 0);
	}
	else if (getInputManager().keyboard().isKeyDown(sf::Keyboard::Key::Down))
	{
		m_charAnim.move(0, 1);
	}
	else if (getInputManager().keyboard().isKeyDown(sf::Keyboard::Key::Up))
	{
		m_charAnim.move(0, -1);
	}
}

void IngameState::onDraw(sf::RenderWindow & window)
{
	window.draw(m_charAnim);
}
