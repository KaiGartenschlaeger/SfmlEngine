#include "Vectors.hpp"

namespace sf
{
	namespace Math
	{

		float length(Vector2<float> const & vector)
		{
			return
				sqrt(lengthSquared(vector));
		}

		float lengthSquared(Vector2<float> const & vector)
		{
			return
				vector.x * vector.x +
				vector.y * vector.y;
		}

		void normalize(Vector2<float> & vector)
		{
			float l = length(vector);
			if (l > 0.f)
			{
				vector /= l;
			}
		}

		void negate(Vector2<float>& vector)
		{
			vector.x = -vector.x;
			vector.y = -vector.y;
		}

		Vector2f min(Vector2f const & vectorA, Vector2f const & vectorB)
		{
			Vector2f result;
			result.x = vectorA.x < vectorB.x ? vectorA.x : vectorB.x;
			result.y = vectorA.y < vectorB.y ? vectorA.y : vectorB.y;

			return result;
		}

		Vector2f max(Vector2f const & vectorA, Vector2f const & vectorB)
		{
			Vector2f result;
			result.x = vectorA.x > vectorB.x ? vectorA.x : vectorB.x;
			result.y = vectorA.y > vectorB.y ? vectorA.y : vectorB.y;

			return result;
		}

	}
}