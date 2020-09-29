#include <SFML/Graphics.hpp>
#include "Player.h"
#include "AlienManager.h"
#include "Bullet.h"
#include "Bunker.h"
#include <string>
#include "EasySFML.h"
#include <algorithm>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 1000), "Space Invaders - Nerys Thamm");
	srand(764387493475);
	sf::Event event;
	
	CPlayer player;
	CAlienManager manager;

	
	
	int iScore = 0;
	sf::Text score;
	score.setPosition(sf::Vector2f(10, 10));
	score.setFillColor(sf::Color::White);
	sf::Font font;
	font.loadFromFile("Resources/sansation.ttf");
	score.setFont(font);
	CBunker bunker(125, 800);
	CBunker bunker2(275, 800);
	CBunker bunker3(425, 800);
	CBunker bunker4(575, 800);
	
	
	while (window.isOpen())
	{
		
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}

		}

		
		
		window.clear();
		CObjectController::UpdateObjects();

		

		score.setString(std::to_string(CGame::score));


		CWindowUtilities::Draw(&score);
		for each (sf::Drawable* Draw in CWindowUtilities::ToDrawList)
		{
			window.draw(*Draw);
		}
		CWindowUtilities::ToDrawList.clear();
		CLaser* LaserToYeet = nullptr;
		for each (CLaser* laser in CAlien::Lasers)
		{
			if (
				bunker.CheckCollisions(laser->laserRect) ||
				bunker2.CheckCollisions(laser->laserRect) ||
				bunker3.CheckCollisions(laser->laserRect) ||
				bunker4.CheckCollisions(laser->laserRect) ||
				laser->fY >= 1000
				)
			{
				laser->bIsEnabled = false;
			}
		}
		
		if (player.bBulletExists)
		{
			if (
				manager.CheckCollisions(player.pBullet->bulletRect) ||
				bunker.CheckCollisions(player.pBullet->bulletRect) ||
				bunker2.CheckCollisions(player.pBullet->bulletRect) ||
				bunker3.CheckCollisions(player.pBullet->bulletRect) ||
				bunker4.CheckCollisions(player.pBullet->bulletRect) ||
				player.pBullet->fY <= 0
				)
			{
				delete player.pBullet;
				player.bBulletExists = false;
			}
			
		}
		for (int i = 0; i < 5; i++)
		{
			
			for (int j = 0; j < 3; j++)
			{
				if (!bunker.BlockArr[i][j].bIsDestroyed)
				{
					window.draw(bunker.BlockArr[i][j].rect);
				}
				if (!bunker2.BlockArr[i][j].bIsDestroyed)
				{
					window.draw(bunker2.BlockArr[i][j].rect);
				}
				if (!bunker3.BlockArr[i][j].bIsDestroyed)
				{
					window.draw(bunker3.BlockArr[i][j].rect);
				}
				if (!bunker4.BlockArr[i][j].bIsDestroyed)
				{
					window.draw(bunker4.BlockArr[i][j].rect);
				}
				
			}
		}
		
		window.display();


		
	}
	return 0;
}