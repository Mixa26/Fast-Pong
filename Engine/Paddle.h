#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "Ball.h"

class Paddle
{
public:
	Paddle(Vec2 in_loc, Vec2 in_speed);
	void Draw(Graphics& in_gfx);
	void PC(Ball& in_ball);
	void Move(float dt);
	void Allign();
	void Collide(Ball& in_ball);
	int GetHeight();
	int GetWidth();
	Vec2 GetLoc();
public:
	Vec2 speed;
private:
	Vec2 loc;
	constexpr static int width = 20;
	constexpr static int height = 100;
};