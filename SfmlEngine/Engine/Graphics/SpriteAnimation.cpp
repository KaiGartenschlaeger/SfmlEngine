#include "SpriteAnimation.hpp"

// constructor

void SpriteAnimation::onDraw(sf::RenderTarget & target, sf::RenderStates states) const
{
	// todo: implement
}

void SpriteAnimation::onUpdate(GameTime const time)
{
	// todo: implement
}

SpriteAnimation::SpriteAnimation()
	:
	m_sprite(nullptr),
	m_framesPerSecond(3),
	m_frameIndex(0),
	m_frameTime(1.0f / 3)
{
}

// public

SpriteAnimation::~SpriteAnimation()
{
}

void SpriteAnimation::setSprite(AnimatedSprite & sprite)
{
	m_sprite = &sprite;
}

void SpriteAnimation::addFrame(sf::Vector2f framePos, sf::Vector2f frameSize)
{
	SpriteAnimationFrame * frame = new SpriteAnimationFrame(framePos, frameSize);
	m_frames.push_back(*frame);
}

void SpriteAnimation::setFramesPerSecond(unsigned int framesPerSecond)
{
	m_framesPerSecond = framesPerSecond;
	m_frameTime = 1.0f / framesPerSecond;
}

unsigned int SpriteAnimation::getFramesPerSecond()
{
	return m_framesPerSecond;
}
