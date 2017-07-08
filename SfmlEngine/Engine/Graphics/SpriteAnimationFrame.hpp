#pragma once

#include <SFML\System\Vector2.hpp>

struct SpriteAnimationFrame
{

	SpriteAnimationFrame()
		: m_pos(0, 0), m_size(0, 0)
	{
	}

	SpriteAnimationFrame(sf::Vector2f pos, sf::Vector2f size)
		: m_pos(pos), m_size(size)
	{
	}

	sf::Vector2f m_pos;
	sf::Vector2f m_size;

};
