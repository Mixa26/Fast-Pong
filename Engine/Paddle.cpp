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
		speed = Vec2(0, -600);
	}
	else if (in_ball.GetLoc().y + in_ball.GetDimension() > loc.y + height)
	{
		speed = Vec2(0, 600);
	}
	else if (in_ball.GetLoc().y + in_ball.GetDimension() / 2 < loc.y + height / 2)
	{
		speed = Vec2(0, -100);
	}
	else if (in_ball.GetLoc().y + in_ball.GetDimension() / 2 > loc.y + height / 2)
	{
		speed = Vec2(0, 100);
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

void Paddle::Collide(Ball & in_ball)
{
	if ((in_ball.GetLoc().y + in_ball.GetDimension() >= loc.y && in_ball.GetLoc().y <= loc.y + height) && (in_ball.GetLoc().x + in_ball.GetDimension() >= loc.x && in_ball.GetLoc().x <= loc.x + width))
	{
		if (in_ball.GetLoc().y < loc.y + height * 20 / 100 && !hold)
		{
			if (in_ball.speed.x > 0)
			{
				in_ball.speed = Vec2(-500, -800);
			}
			else if (in_ball.speed.x < 0)
			{
				in_ball.speed = Vec2(500, -800);
			}
		}
		else if (in_ball.GetLoc().y < loc.y + height * 40 / 100 && !hold)
		{
			if (in_ball.speed.x > 0)
			{
				in_ball.speed = Vec2(-600, -500);
			}
			else if (in_ball.speed.x < 0)
			{
				in_ball.speed = Vec2(600, -500);
			}
		}
		else if (in_ball.GetLoc().y <= loc.y + height * 50 / 100 && !hold)
		{
			if (in_ball.speed.x > 0)
			{
				in_ball.speed = Vec2(-800, -100);
			}
			else if (in_ball.speed.x < 0)
			{
				in_ball.speed = Vec2(800, -100);
			}
		}
		else if (in_ball.GetLoc().y < loc.y + height * 60 / 100 && !hold)
		{
			if (in_ball.speed.x > 0)
			{
				in_ball.speed = Vec2(-800, 100);
			}
			else if (in_ball.speed.x < 0)
			{
				in_ball.speed = Vec2(800, 100);
			}
		}
		else if (in_ball.GetLoc().y < loc.y + height * 80 / 100 && !hold)
		{
			if (in_ball.speed.x > 0)
			{
				in_ball.speed = Vec2(-600, 500);
			}
			else if (in_ball.speed.x < 0)
			{
				in_ball.speed = Vec2(600, 500);
			}
		}
		else if (in_ball.GetLoc().y < loc.y + height && !hold)
		{
			if (in_ball.speed.x > 0)
			{
				in_ball.speed = Vec2(-500, 700);
			}
			else if (in_ball.speed.x < 0)
			{
				in_ball.speed = Vec2(500, 700);
			}
		}
		hold = true;
	}
	else
	{
		hold = false;
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

void Paddle::SetLoc(Vec2 in_loc)
{
	loc = in_loc;
}
