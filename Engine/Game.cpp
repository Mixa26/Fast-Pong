/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	player1( Vec2(Graphics::ScreenWidth - player1.GetWidth() * 2, Graphics::ScreenHeight / 2 - player1.GetHeight() / 2), Vec2(0, 0)),
	PC( Vec2( PC.GetWidth(), Graphics::ScreenHeight / 2 - player1.GetHeight() / 2 ), Vec2(0, 0)),
	ball( Vec2(float(Graphics::ScreenWidth / 2 - ball.GetDimension() / 2), float(Graphics::ScreenHeight / 2 - ball.GetDimension() / 2)), Vec2(700, 0))
{
	srand(time(NULL));
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float dt = ft.Mark();

	score.Score1(ball, pause);
	score.Score2(ball, pause);

	//player paddle movement processing
	if (!pause) // checks if the game is in pause (someone scored or end of game (10 points))
	{
		if (wnd.kbd.KeyIsPressed(VK_UP) && player1.GetLoc().y > 0.0f)
		{
			player1.speed = Vec2(0, -600);
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN) && player1.GetLoc().y + player1.GetHeight() < Graphics::ScreenHeight - 1.0f)
		{
			player1.speed = Vec2(0, 600);
		}
		else
		{
			player1.speed = Vec2(0, 0);
		}

		player1.Move(dt);
		PC.PC(ball);	//computer playing AI
		PC.Move(dt);
		ball.Move(dt);
	}
	else if (wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		pause = false;
		player1.SetLoc(Vec2(Graphics::ScreenWidth - player1.GetWidth() * 2, Graphics::ScreenHeight / 2 - player1.GetHeight() / 2));
		PC.SetLoc(Vec2(PC.GetWidth(), Graphics::ScreenHeight / 2 - player1.GetHeight() / 2));
		if (rand() % 2 == 1)
		{
			ball.speed = Vec2(700, 0);
		}
		else
		{
			ball.speed = Vec2(-700, 0);
		}
		if (score.score1 >= 10 || score.score2 >= 10)
		{
			score.score1 = 0;
			score.score2 = 0;
		}
	}

	//all the collisions to keep stuff on the screen
	player1.Allign(); //keeps the pedals on the screen
	PC.Allign();
	ball.WallCollide();
	player1.Collide(ball);
	PC.Collide(ball);
}

void Game::ComposeFrame()
{
	//all the in game graphic drawing
	score.DrawScore(Vec2(350, 20), score.score1, gfx);
	score.DrawScore(Vec2(450, 20), score.score2, gfx);
	player1.Draw(gfx);
	PC.Draw(gfx);
	ball.Draw(gfx);
}
