#pragma once

#include "SpriteAnimation.hpp"

class TiledSpriteAnimation : public SpriteAnimation
{

private:

	unsigned int m_tilesCountX;
	unsigned int m_tilesCountY;

public:

	TiledSpriteAnimation(unsigned int tilesCountX, unsigned int tilesCountY);
	~TiledSpriteAnimation();

	void addFrame(unsigned int tileX, unsigned int tileY);

};
