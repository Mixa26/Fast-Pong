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

void Score::DrawBlock(Graphics& in_gfx, int j, int i)
{
	for (int y = j; y < j + dimension; y++)
	{
		for (int x = i; x < i + dimension; x++)
		{
			in_gfx.PutPixel(x, y, Colors::White);
		}
	}
}

void Score::DrawScore(Vec2 in_pos, int score)
{
	switch (score)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	}
}
