#include "Vector2.hpp"

namespace Math
{
	Vector2::Vector2()
	{
		x = 0, y = 0;
	}

	Vector2::Vector2(float init_x, float init_y)
	{
		x = init_x, y = init_y;
	}

	Vector2 Vector2::Lerp(Vector2 end, float t)
	{
		t = std::clamp(t, 0.0f, 1.0f);

		return {
			x + (end.x - x) * t,
			y + (end.y - y) * t
		};
	}

	Vector2 Vector2::Lerp(float t)
	{
		t = std::clamp(t, 0.0f, 1.0f);

		return {
			x * t,
			y * t
		};
	}

	Vector2 Vector2::Floor()
	{
		return {
			std::floor(x),
			std::floor(y)
		};
	}

	Vector2 Vector2::Ceil()
	{
		return {
			std::ceil(x),
			std::ceil(y)
		};
	}

	float Vector2::Length()
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	Vector2 Vector2::Abs()
	{
		return {
			fabs(x),
			fabs(y)
		};
	}
}