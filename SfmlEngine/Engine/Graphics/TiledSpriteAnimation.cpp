#include "TiledSpriteAnimation.hpp"

TiledSpriteAnimation::TiledSpriteAnimation(unsigned int tilesCountX, unsigned int tilesCountY)
	:
	m_tilesCountX(tilesCountX),
	m_tilesCountY(tilesCountY)
{
}

TiledSpriteAnimation::~TiledSpriteAnimation()
{
}

void TiledSpriteAnimation::addFrame(unsigned int tileX, unsigned int tileY)
{
	if (m_sprite == nullptr)
		return;

	sf::Vector2u textureSize = m_sprite->getTextureSize();

	float frameWidth = static_cast<float>(textureSize.x) / m_tilesCountX;
	float frameHeight = static_cast<float>(textureSize.y) / m_tilesCountY;

	SpriteAnimation::addFrame(
		sf::Vector2f(tileX * frameWidth, tileY * frameHeight),
		sf::Vector2f(frameWidth, frameHeight));
}
