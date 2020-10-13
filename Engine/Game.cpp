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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	player1( Vec2(Graphics::ScreenWidth - player1.GetWidth() * 2, Graphics::ScreenHeight / 2 - player1.GetHeight() / 2), Vec2(0, 0)),
	PC( Vec2( PC.GetWidth(), Graphics::ScreenHeight / 2 - player1.GetHeight() / 2 ), Vec2(0, 0)),
	ball( Vec2(float(Graphics::ScreenWidth / 2 - ball.GetDimension() / 2), float(Graphics::ScreenHeight / 2 - ball.GetDimension() / 2)), Vec2(0, 0))
{
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

	if (wnd.kbd.KeyIsPressed(VK_UP) && player1.GetLoc().y > 0.0f)
	{
		player1.speed = Vec2(0, -500);
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN) && player1.GetLoc().y + player1.GetHeight() < Graphics::ScreenHeight - 1.0f)
	{
		player1.speed = Vec2(0, 500);
	}
	else
	{
		player1.speed = Vec2(0, 0);
	}

	player1.Move(dt);
	ball.Move(dt);

	player1.Allign();
}

void Game::ComposeFrame()
{
	player1.Draw(gfx);
	PC.Draw(gfx);
	ball.Draw(gfx);
}
