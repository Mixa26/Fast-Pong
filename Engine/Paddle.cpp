#include "Paddle.h"

Paddle::Paddle(Vec2 in_loc, Vec2 in_speed)
{
	loc = in_loc;
	speed = in_speed;
}

void Paddle::Draw(Graphics& in_gfx)
{
	for (int y = int(loc.y); y < loc.y + height; y++)
	{
		for (int x = int(loc.x); x < loc.x + width; x++)
		{
			in_gfx.PutPixel(x, y, Colors::White);
		}
	}
}

void Paddle::PC(Ball& in_ball)
{
	if (in_ball.GetLoc().y < loc.y)
	{

	}
	else if (in_ball.GetLoc().y + in_ball.GetDimension() > loc.y + height)
	{

	}
	else if (in_ball.GetLoc().y + in_ball.GetDimension() / 2 < loc.y + height / 2)
	{

	}
	else if (in_ball.GetLoc().y + in_ball.GetDimension() / 2 > loc.y + height / 2)
	{

	}
}

void Paddle::Move(float dt)
{
	loc += speed * dt;
}

void Paddle::Allign()
{
	if (loc.y < 0)
	{
		loc.y = 0;
	}
	if (loc.y + height + 1> Graphics::ScreenHeight)
	{
		loc.y = Graphics::ScreenHeight - height - 1;
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

Vec2 Paddle::GetLoc()
{
	return loc;
}
