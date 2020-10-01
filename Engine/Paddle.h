#pragma once

#include "Vec2.h"
#include "Graphics.h"

class Paddle
{
public:
	Paddle(Vec2 in_loc);
	void Draw(Graphics& in_gfx);
	void PC();
	bool Collision();
	int GetHeight();
	int GetWidth();
private:
	Vec2 loc;
	constexpr static int width = 20;
	constexpr static int height = 100;
};