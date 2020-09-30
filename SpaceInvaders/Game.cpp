#include <SFML/Graphics.hpp>
#include "player.h"
#include "Alienmanager.h"
#include "Bullet.h"
#include "Bunker.h"
#include <string>
#include "EasySFML.h"
#include <algorithm>
#include "Game.h"
#include "DebugWindow.h"


CGame::CGame()
{
	
}


CGame::~CGame()
{
	
}

int CGame::Start()
{
	sf::RenderWindow window(sf::VideoMode(800, 1000), "Space Invaders - Nerys Thamm");
	srand(764387493475);
	sf::Event event;
	debug = nullptr;

	CGame::score = 0;
	CGame::iLevel = 1;

	
	bool bIsPlaying = true;
	sf::Font font;
	font.loadFromFile("Resources/sansation.ttf");
	CPlayer* player = new CPlayer();
	CAlienManager* manager = new CAlienManager();
	sf::Text score;
	score.setPosition(sf::Vector2f(10, 10));
	score.setFillColor(sf::Color::White);
	score.setFont(font);
	sf::Text lives;
	lives.setPosition(sf::Vector2f(650, 10));
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
				bIsPlaying = false;
				window.close();
				if (debug != nullptr)
				{
					delete debug;
				}
				bDebugMode = false;
				CWindowUtilities::ToDrawList.clear();
				delete player;
				delete manager;
				CAlien::DeleteLasers();
				return 0;
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					if (debug == nullptr)
					{
						debug = new DebugWindow();
						bDebugMode = true;
					}
					else
					{
						
						bDebugMode = false;
					}
					break;
				default:
					break;
				}
			default:
				break;
			}

		}

		window.clear();
		if (debug != nullptr)
		{
			if (!bDebugMode)
			{
				delete debug;
				debug = nullptr;
				
			}
		}

		if (manager->MoveAliens() || CGame::iPlayerLives <= 0)
		{
			if (debug != nullptr)
			{
				delete debug;
			}
			bDebugMode = false;
			bIsPlaying = false;
			
			window.close();
			CWindowUtilities::ToDrawList.clear();
			delete player;
			delete manager;
			CAlien::DeleteLasers();
			return CGame::score;
		}
		CObjectController::UpdateObjects();



		if (manager->iRemainingAliens <= 0)
		{
			delete manager;
			manager = new CAlienManager();
			CGame::iLevel++;
		}



		score.setString("Score: [ " + std::to_string(CGame::score) + " ]");
		lives.setString("Lives: [ " + std::to_string(CGame::iPlayerLives) + " ]");
		CWindowUtilities::Draw(&score);
		CWindowUtilities::Draw(&lives);

		for each (sf::Drawable* Draw in CWindowUtilities::ToDrawList)
		{
			window.draw(*Draw);
		}
		CWindowUtilities::ToDrawList.clear();
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
		window.display();
	}
}

int CGame::score = 0;
bool CGame::bDebugMode = false;
int CGame::iAlienSpeedMult = 1;
int CGame::iBulletSpeedMult = 1;
int CGame::iPlayerLives = 3;
int CGame::iLevel = 1;