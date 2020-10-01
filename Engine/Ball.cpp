#include "Ball.h"

Ball::Ball(Vec2 in_loc)
{
	loc = in_loc;
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
