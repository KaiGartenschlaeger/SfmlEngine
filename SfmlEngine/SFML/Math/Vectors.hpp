#pragma once

#include <cmath>
#include <SFML\System\Vector2.hpp>

namespace sf
{
	namespace Math
	{

		float length(sf::Vector2<float> const & vector);
		float lengthSquared(sf::Vector2<float> const & vector);

		void normalize(sf::Vector2<float> & vector);

		void negate(sf::Vector2<float> & vector);

		sf::Vector2f min(sf::Vector2f const & vectorA, sf::Vector2f const & vectorB);
		sf::Vector2f max(sf::Vector2f const & vectorA, sf::Vector2f const & vectorB);

	}
}