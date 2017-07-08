#include "AnimatedSprite.hpp"

// constructor

AnimatedSprite::AnimatedSprite()
	: m_texture(nullptr)
{
}

AnimatedSprite::~AnimatedSprite()
{
}

// protected

void AnimatedSprite::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (m_texture == nullptr || m_currentAnimation == nullptr)
		return;

	m_currentAnimation->onDraw(target, states);
}

// public

void AnimatedSprite::setTexture(const sf::Texture & texture)
{
	m_texture = &texture;
}

SpriteAnimation * AnimatedSprite::setAnimation(std::string name)
{
	auto it = m_animations.find(name);
	if (it != m_animations.end())
	{
		SpriteAnimation * animToSet = &(*it).second;

		m_currentAnimation = animToSet;

		return animToSet;
	}

	return nullptr;
}

bool AnimatedSprite::addAnimation(SpriteAnimation & animation, std::string name, bool setActive)
{
	bool added = m_animations.insert(
		std::pair<std::string, SpriteAnimation>(name, animation)).second;

	if (added && setActive)
		m_currentAnimation = &animation;

	return added;
}

bool AnimatedSprite::removeAnimation(std::string name)
{
	auto it = m_animations.find(name);
	if (it != m_animations.end())
	{
		m_animations.erase(it);
		return true;
	}

	return false;
}

SpriteAnimation * AnimatedSprite::getAnimation(std::string name)
{
	auto it = m_animations.find(name);
	if (it != m_animations.end())
	{
		return &(*it).second;
	}

	return nullptr;
}

sf::Vector2u AnimatedSprite::getTextureSize()
{
	return m_texture->getSize();
}

void AnimatedSprite::update(GameTime const time)
{
	if (m_texture == nullptr || m_currentAnimation == nullptr)
		return;

	m_currentAnimation->onUpdate(time);
}
