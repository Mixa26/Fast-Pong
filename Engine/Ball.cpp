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

void Ball::WallCollide()
{
	if (loc.y < 0)
	{
		loc.y = 0;
		speed.y *= -1;
	}
	if (loc.y + dimension > Graphics::ScreenHeight - 1)
	{
		loc.y = Graphics::ScreenHeight - dimension - 1;
		speed.y *= -1;
	}
}

Vec2 Ball::GetLoc()
{
	return loc;
}

void Ball::SetLoc(Vec2 in_loc)
{
	loc = in_loc;
}
