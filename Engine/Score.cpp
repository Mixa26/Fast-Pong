#include "Score.h"

bool Score::Score1(Ball & in_ball, bool& in_pause)
{
	if (in_ball.GetLoc().x + in_ball.GetDimension() >= Graphics::ScreenWidth - 10.0f)
	{
		in_ball.speed = Vec2(0, 0);
		in_ball.SetLoc(Vec2(Graphics::ScreenWidth / 2 - in_ball.GetDimension() / 2, Graphics::ScreenHeight / 2 - in_ball.GetDimension() / 2));
		score1++;
		in_pause = true;
		return true;
	}
	return false;
}

bool Score::Score2(Ball & in_ball, bool& in_pause)
{
	if (in_ball.GetLoc().x < 10.0f)
	{
		in_ball.speed = Vec2(0, 0);
		in_ball.SetLoc(Vec2(Graphics::ScreenWidth / 2 - in_ball.GetDimension() / 2, Graphics::ScreenHeight / 2 - in_ball.GetDimension() / 2));
		score2++;
		in_pause = true;
		return true;
	}
	return false;
}

void Score::DrawBlock(Graphics& in_gfx, int i, int j)
{
	for (int y = j; y < j + dimension; y++)
	{
		for (int x = i; x < i + dimension; x++)
		{
			in_gfx.PutPixel(x, y, Colors::White);
		}
	}
}

void Score::DrawScore(Vec2 in_pos, int score, Graphics& in_gfx)
{
	switch (score)
	{
	case 0:
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 30);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 30);
		break;
	case 1:
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 30);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 40);
		break;
	case 2:
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y + 30);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 40);
		break;
	case 3:
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 30);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 30);
		break;
	case 4:
		DrawBlock(in_gfx, in_pos.x, in_pos.y);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 30);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 40);
		break;
	case 5:
		DrawBlock(in_gfx, in_pos.x, in_pos.y);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 30);
		break;
	case 6:
		DrawBlock(in_gfx, in_pos.x, in_pos.y);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 30);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 30);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 40);
		break;
	case 7:
		DrawBlock(in_gfx, in_pos.x, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 30);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 40);
		break;
	case 8:
		DrawBlock(in_gfx, in_pos.x, in_pos.y);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 30);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 30);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 40);
		break;
	case 9:
		DrawBlock(in_gfx, in_pos.x, in_pos.y);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 30);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 40);
		break;
	case 10:
		DrawBlock(in_gfx, in_pos.x - 30, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x - 20, in_pos.y);
		DrawBlock(in_gfx, in_pos.x - 20, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x - 20, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x - 20, in_pos.y + 30);
		DrawBlock(in_gfx, in_pos.x - 20, in_pos.y + 40);

		DrawBlock(in_gfx, in_pos.x, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + 30);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 10, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + 20, in_pos.y + 40);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 10);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 20);
		DrawBlock(in_gfx, in_pos.x + 30, in_pos.y + 30);
		break;
	}
}
