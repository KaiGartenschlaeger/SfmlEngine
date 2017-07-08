#pragma once

#include <iostream>
#include "..\Engine\States\GameState.hpp"
#include "..\Engine\Graphics\AnimatedSprite.hpp"
#include "..\Engine\Graphics\TiledSpriteAnimation.hpp"
#include "..\Sfml\Colors.hpp"

class IngameState : public GameState
{

private:

	sf::Texture m_charTexture;
	AnimatedSprite m_charAnim;

public:

	IngameState();
	~IngameState();

protected:

	virtual void onLoad() override;
	virtual void onUnload() override;

	virtual void onActivate() override;
	virtual void onInactivate() override;

	virtual void onEvent(sf::Event const & event) override;
	virtual void onUpdate(GameTime const time) override;
	virtual void onDraw(sf::RenderWindow & window) override;
	
};