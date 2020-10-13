#include "Ball.h"

Ball::Ball(Vec2 in_loc,Vec2 in_speed)
{
	loc = in_loc;
	speed = in_speed;
}

void Ball::Draw(Graphics& in_gfx)
{
	for (int y = loc.y; y < loc.y + dimension; y++)
	{
		for (int x = loc.x; x < loc.x + dimension; x++)
		{
			in_gfx.PutPixel(x, y, Colors::White);
		}
	}
}

int Ball::GetDimension()
{
	return dimension;
}

void Ball::Move(float dt)
{
	loc += speed * dt;
}
