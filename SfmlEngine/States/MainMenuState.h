#pragma once

#include <iostream>
#include "SFML\Graphics.hpp"
#include "..\Engine\States\GameState.hpp"
#include "..\Sfml\Colors.hpp"

class MainMenuState : public GameState
{

public:

	MainMenuState();
	~MainMenuState();

private:

	sf::Font m_font;
	sf::Text m_startGame;
	sf::Text m_exit;
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

	int m_selectedEntry = 0;
	const int MaxSelectedEntry = 1;

	const sf::Color ActiveEntryColor = sf::Colors::White;
	const sf::Color InactiveEntryColor = sf::Colors::DarkSlateGray;

	void initText(sf::Text & textObj, std::string stringToSet, float posX, float posY);
	void refreshSelectedEntryColor();

protected:

	virtual void onLoad() override;
	virtual void onUnload() override;

	virtual void onActivate() override;
	virtual void onInactivate() override;

	virtual void onEvent(sf::Event const & event) override;
	virtual void onUpdate(GameTime const time) override;
	virtual void onDraw(sf::RenderWindow & window) override;

};