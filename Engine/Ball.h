#pragma once

#include "Vec2.h"
#include "Graphics.h"

class Ball
{
public:
	Ball() = default;
	Ball(Vec2 in_loc, Vec2 in_speed);
	void Draw(Graphics& in_gfx);
	int GetDimension();
	void Move(float dt);
	void WallCollide();
	Vec2 GetLoc();
public:
	Vec2 speed;
private:
	Vec2 loc;
	constexpr static int dimension = 20;
};