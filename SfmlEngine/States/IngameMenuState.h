#pragma once

#include <iostream>
#include "..\Engine\States\GameState.hpp"

class IngameMenuState : public GameState
{

public:

	IngameMenuState();
	~IngameMenuState();

protected:

	virtual void onLoad() override;
	virtual void onUnload() override;

	virtual void onActivate() override;
	virtual void onInactivate() override;

	virtual void onEvent(sf::Event const & event) override;
	virtual void onUpdate(GameTime const time) override;
	virtual void onDraw(sf::RenderWindow & window) override;

};