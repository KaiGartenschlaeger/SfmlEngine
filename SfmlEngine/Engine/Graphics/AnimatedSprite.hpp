#pragma once

#include <map>
#include <SFML\Graphics.hpp>
#include "..\GameTime.hpp"
#include "SpriteAnimation.hpp"

class SpriteAnimation;

class AnimatedSprite : public sf::Drawable, public sf::Transformable
{

private:

	const sf::Texture * m_texture;

	std::map<std::string, SpriteAnimation> m_animations;
	SpriteAnimation * m_currentAnimation = nullptr;

protected:

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

public:

	AnimatedSprite();
	~AnimatedSprite();

	void setTexture(const sf::Texture & texture);

	SpriteAnimation * setAnimation(std::string name);

	bool addAnimation(SpriteAnimation & animation, std::string name, bool setActive = false);
	bool removeAnimation(std::string name);

	SpriteAnimation * getAnimation(std::string name);

	sf::Vector2u getTextureSize();

	void update(GameTime const time);

};
