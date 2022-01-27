#ifndef _VECTOR2_HPP
#define _VECTOR2_HPP

#include <algorithm>
#include <cmath>

//pasted this class https://www.unknowncheats.me/forum/rust/390615-paste-recoil-script.html

namespace Math
{

	class Vector2
	{
	public:

		Vector2();

		Vector2(float x, float y);

		Vector2 Lerp(float t);

		Vector2 Lerp(Vector2 end, float t);

		Vector2 Floor();

		Vector2 Ceil();

		Vector2 Abs();

		float Length();

		Vector2 operator - (Vector2 other)
		{
			return {
				x - other.x,
				y - other.y
			};
		}

		Vector2 operator + (Vector2 other)
		{
			return {
				x + other.x,
				y + other.y
			};
		}

		Vector2 operator * (Vector2 other)
		{
			return {
				x * other.x,
				y * other.y
			};
		}

		Vector2 operator / (Vector2 other)
		{
			return {
				x / other.x,
				y / other.y
			};
		}

		void operator += (Vector2 other)
		{
			x += other.x;
			y += other.y;
		}

		void operator -= (Vector2 other)
		{
			x -= other.x;
			y -= other.y;
		}

		void operator *= (Vector2 other)
		{
			x *= other.x;
			y *= other.y;
		}

		void operator /= (Vector2 other)
		{
			x /= other.x;
			y /= other.y;
		}

	public: 
		float x, y;
	};
}
#endif