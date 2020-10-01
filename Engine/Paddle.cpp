#include "Paddle.h"

Paddle::Paddle(Vec2 in_loc)
{
	loc = in_loc;
}

void Paddle::Draw(Graphics& in_gfx)
{
	for (int y = loc.y; y < loc.y + height; y++)
	{
		for (int x = loc.x; x < loc.x + width; x++)
		{
			in_gfx.PutPixel(x, y, Colors::White);
		}
	}
}

int Paddle::GetHeight()
{
	return height;
}

int Paddle::GetWidth()
{
	return width;
}
