#pragma once

#include "Graphics.h"
#include "Ball.h"

class Score
{
public:
	Score() = default;
	bool Score1(Ball& in_ball, bool& in_pause);
	bool Score2(Ball& in_ball, bool& in_pause);
	void DrawBlock(Graphics& in_gfx, int j, int i);
	void DrawScore(Vec2 in_pos, int score);
public:
	int dimension = 10;
	int score1 = 0;
	int score2 = 0;
};