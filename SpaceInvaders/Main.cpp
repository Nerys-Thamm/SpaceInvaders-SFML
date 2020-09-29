#include <SFML/Graphics.hpp>
#include "player.h"
#include "Alienmanager.h"
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
	
	

	
	
	int iScore = 0;
	bool bInMenu = true;
	bool bIsPlaying = false;
	sf::Font font;
	font.loadFromFile("Resources/sansation.ttf");
	sf::Text title;
	sf::Text prompt;
	title.setPosition(300, 400);
	title.setFillColor(sf::Color::White);
	title.setFont(font);
	title.setString("Space Invaders");
	prompt.setPosition(350, 500);
	prompt.setFillColor(sf::Color::White);
	prompt.setFont(font);
	prompt.setString("Press Spacebar to play");

	CGame game;
	
	
	while (window.isOpen())
	{

		while (bInMenu)
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				game.Start();
			}
			else
			{
				window.draw(title);
				window.draw(prompt);
				window.display();
			}


		}


		/*
		CPlayer* player = new CPlayer();
		CAlienManager* manager = new CAlienManager();
		sf::Text score;
		score.setPosition(sf::Vector2f(10, 10));
		score.setFillColor(sf::Color::White);
		score.setFont(font);
		sf::Text lives;
		lives.setPosition(sf::Vector2f(400, 10));
		lives.setFillColor(sf::Color::White);
		lives.setFont(font);
		CBunker bunker(125, 800);
		CBunker bunker2(275, 800);
		CBunker bunker3(425, 800);
		CBunker bunker4(575, 800);
		while (bIsPlaying)
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


			if (manager->MoveAliens() || player->Lives <= 0)
			{
				bIsPlaying = false;
			}
			CObjectController::UpdateObjects();



			if (manager->iRemainingAliens <= 0)
			{
				delete manager;
				manager = new CAlienManager();
			}



			score.setString(std::to_string(CGame::score));
			lives.setString(std::to_string(player->Lives));
			CWindowUtilities::Draw(&score);
			CWindowUtilities::Draw(&lives);

			for each (sf::Drawable* Draw in CWindowUtilities::ToDrawList)
			{
				window.draw(*Draw);
			}
			CWindowUtilities::ToDrawList.clear();
			CLaser* LaserToYeet = nullptr;
			for each (CLaser* laser in CAlien::Lasers)
			{
				if (laser->bIsEnabled)
				{
					if (
						bunker.CheckCollisions(laser->laserRect) ||
						bunker2.CheckCollisions(laser->laserRect) ||
						bunker3.CheckCollisions(laser->laserRect) ||
						bunker4.CheckCollisions(laser->laserRect) ||
						player->CheckCollision(laser->laserRect) ||
						laser->fY >= 1000
						)
					{
						laser->bIsEnabled = false;
					}
				}
			}

			if (player->bBulletExists)
			{
				if (
					manager->CheckCollisions(player->pBullet->bulletRect) ||
					bunker.CheckCollisions(player->pBullet->bulletRect) ||
					bunker2.CheckCollisions(player->pBullet->bulletRect) ||
					bunker3.CheckCollisions(player->pBullet->bulletRect) ||
					bunker4.CheckCollisions(player->pBullet->bulletRect) ||
					player->pBullet->fY <= 0
					)
				{
					delete player->pBullet;
					player->bBulletExists = false;
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
		CWindowUtilities::ToDrawList.clear();
		delete player;
		delete manager;
		bInMenu = true;
		*/
	}
	return 0;
}