#pragma once

#include "Vec2.h"
#include "Graphics.h"

class Ball
{
public:
	Ball() = default;
	Ball(Vec2 in_loc);
	void Draw(Graphics& in_gfx);
	int GetDimension();
private:
	Vec2 loc;
	constexpr static int dimension = 20;
};