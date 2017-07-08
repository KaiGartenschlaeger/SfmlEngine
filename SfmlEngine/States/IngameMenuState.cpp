#include "IngameMenuState.h"

IngameMenuState::IngameMenuState()
	: GameState("IngameMenu")
{
	std::cout << "IngameMenu ctor\n";
}

IngameMenuState::~IngameMenuState()
{
	std::cout << "IngameMenu dctor\n";
}

void IngameMenuState::onLoad()
{
	std::cout << "IngameMenu onLoad\n";
}

void IngameMenuState::onUnload()
{
	std::cout << "IngameMenu onUnload\n";
}

void IngameMenuState::onActivate()
{
	std::cout << "IngameMenu onActivate\n";
}

void IngameMenuState::onInactivate()
{
	std::cout << "IngameMenu onInactivate\n";
}

void IngameMenuState::onEvent(sf::Event const & event)
{
}

void IngameMenuState::onUpdate(GameTime const time)
{
}

void IngameMenuState::onDraw(sf::RenderWindow & window)
{
}
