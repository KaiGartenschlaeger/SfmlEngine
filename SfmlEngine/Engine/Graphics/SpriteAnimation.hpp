#pragma once

#include <vector>
#include <SFML\System\Vector2.hpp>
#include "AnimatedSprite.hpp"
#include "SpriteAnimationFrame.hpp"

class AnimatedSprite;

class SpriteAnimation
{

private:

	friend class AnimatedSprite;

	unsigned int m_frameIndex;
	unsigned int m_framesPerSecond;
	float m_frameTime;
	std::vector<SpriteAnimationFrame> m_frames;

	void onDraw(sf::RenderTarget & target, sf::RenderStates states) const;
	void onUpdate(GameTime const time);

protected:

	AnimatedSprite * m_sprite;

public:

	SpriteAnimation();
	~SpriteAnimation();

	void setSprite(AnimatedSprite & sprite);

	void addFrame(sf::Vector2f framePos, sf::Vector2f frameSize);

	void setFramesPerSecond(unsigned int framesPerSecond);
	unsigned int getFramesPerSecond();

};
