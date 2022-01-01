#pragma once
#include "Vector2.hpp"


namespace Stuff {


	Math::Vector2 getPos(Math::Vector2 in, Math::Vector2 last_shot) {

		//cur shot - last shot
		float tmpX = in.x;
		float tmpY = in.y;

		float dx = tmpX - last_shot.x;
		float dy = tmpY - last_shot.y;

		float mult = -0.03f * (0.6 * 3.0f) * (90 / 100.0f);
		float px_x = dx / mult;
		float px_y = dy / mult;
		last_shot = in;

		return Math::Vector2(px_x, px_y);
	}

}