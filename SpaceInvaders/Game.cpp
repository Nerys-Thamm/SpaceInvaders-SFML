////////////////////////////////////////////////////////////
//==========================================================
// Bachelor of Software Engineering                       
// Media Design School                                    
// Auckland                                               
// New Zealand                                            
//----------------------------------------------------------
// (c) 2020 Media Design School                           
//==========================================================
//   File Name  : Game.cpp                          
//----------------------------------------------------------
//  Description : Contains the implementation for the     
//  CGame class.                                                      
//                                                        
//                                                        
//----------------------------------------------------------
//    Author    : Nerys Thamm BSE20021                    
//----------------------------------------------------------
//    E-mail    : NerysThamm@gmail.com                    
//==========================================================
////////////////////////////////////////////////////////////
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

int CGame::Start()
{
	sf::RenderWindow window(sf::VideoMode(800, 1000), "Space Invaders - Nerys Thamm"); //Create the game window
	srand(764387493475); //Initialise the randomizer
	sf::Event event; //Initialise the event stack
	debug = nullptr; //set the DebugWindow pointer to be nullptr

	CGame::score = 0; //Set Score to 0 and level to 1
	CGame::iLevel = 1;

	bool bIsPlaying = true; //Set bIsPlaying to true

	sf::Font font; //Load font from resources
	font.loadFromFile("Resources/sansation.ttf");

	CPlayer* player = new CPlayer(); //Create new player
	CAlienManager* manager = new CAlienManager(); //Spawn a wave of aliens

	sf::Text score; //Create text to display the players score
	score.setPosition(sf::Vector2f(10, 10));
	score.setFillColor(sf::Color::White);
	score.setFont(font);

	sf::Text lives; //Create text to display the players remaining lives
	lives.setPosition(sf::Vector2f(650, 10));
	lives.setFillColor(sf::Color::White);
	lives.setFont(font);

	CBunker bunker(125, 800); //Instantiate and position 4 bunkers
	CBunker bunker2(275, 800);
	CBunker bunker3(425, 800);
	CBunker bunker4(575, 800);

	while (bIsPlaying) //While the game is being played
	{
		while (window.pollEvent(event)) //Read all events
		{
			switch (event.type) // if the type of event is...
			{
			case sf::Event::Closed: //the window being closed...
				bIsPlaying = false; 
				window.close(); //close the window

				//free up memory

				if (debug != nullptr)
				{
					delete debug;
				}
				bDebugMode = false;
				CWindowUtilities::ToDrawList.clear();
				delete player;
				delete manager;
				CAlien::DeleteLasers();

				return 0; //Return to main menu with 0 score due to [x]ing out of the window
				break;
			case sf::Event::KeyPressed: //A key being pressed...
				switch (event.key.code) //If that key is...
				{
				case sf::Keyboard::Escape: //The Escape Key...
					if (debug == nullptr) //If the Debug menu doesnt already exist, make one and turn debug mode on
					{
						debug = new DebugWindow();
						bDebugMode = true;
					}
					else //Otherwise, turn debug mode off
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

		window.clear();//Clear the window

		if (debug != nullptr)//If a debug window exists and Debug mode isnt on, close the debug window and free up its memory
		{
			if (!bDebugMode)
			{
				delete debug;
				debug = nullptr;
				
			}
		}

		if (manager->MoveAliens() || CGame::iPlayerLives <= 0) //If the aliens reach the bottom of the screen or the player runs out of lives...
		{
			//Free up memory

			if (debug != nullptr)
			{
				delete debug;
			}
			bDebugMode = false;
			bIsPlaying = false;
			
			window.close(); //Close the game window

			CWindowUtilities::ToDrawList.clear(); //Clear the drawing list

			//Free up memory
			delete player;
			delete manager;
			CAlien::DeleteLasers();

			return CGame::score; //Return the players current score to the main menu
		}


		CObjectController::UpdateObjects(); //Update all GameObjects


		if (manager->iRemainingAliens <= 0) //If every alien in the wave has been defeated...
		{
			delete manager;
			manager = new CAlienManager(); //replace the wave with a new one
			CGame::iLevel++; //and increase the level by one
		}

		score.setString("Score: [ " + std::to_string(CGame::score) + " ]"); //Set the value of the player score and life GUI elements
		lives.setString("Lives: [ " + std::to_string(CGame::iPlayerLives) + " ]");

		CWindowUtilities::Draw(&score); //add them to the draw list
		CWindowUtilities::Draw(&lives);

		for each (sf::Drawable* Draw in CWindowUtilities::ToDrawList) //Draw every object on the draw list
		{
			window.draw(*Draw);
		}
		CWindowUtilities::ToDrawList.clear(); //Then empty it so its ready for the next frame

		for each (CLaser* laser in CAlien::Lasers) //For every laser that exists this frame
		{
			if (laser->bIsEnabled) //If it is enabled
			{
				if (											//Check if it has hit one of the bunkers, or if it has left the screen
					bunker.CheckCollisions(laser->laserRect) ||
					bunker2.CheckCollisions(laser->laserRect) ||
					bunker3.CheckCollisions(laser->laserRect) ||
					bunker4.CheckCollisions(laser->laserRect) ||
					player->CheckCollision(laser->laserRect) ||
					laser->fY >= 1000
					)
				{
					laser->bIsEnabled = false; //If so, disable the laser
				}
			}
		}

		if (player->bBulletExists) //If the player currently has a bullet spawned
		{
			if (															//Check if the bullet is colliding with a bunker, or if it has left the screen
				manager->CheckCollisions(player->pBullet->bulletRect) ||
				bunker.CheckCollisions(player->pBullet->bulletRect) ||
				bunker2.CheckCollisions(player->pBullet->bulletRect) ||
				bunker3.CheckCollisions(player->pBullet->bulletRect) ||
				bunker4.CheckCollisions(player->pBullet->bulletRect) ||
				player->pBullet->fY <= 0
				)
			{
				delete player->pBullet;  //If so, despawn the bullet
				player->bBulletExists = false;
			}

		}
		window.display();//Display the drawn frame to the window
	}
}


int CGame::score = 0;
bool CGame::bDebugMode = false;
int CGame::iAlienSpeedMult = 1;
int CGame::iBulletSpeedMult = 1;
int CGame::iPlayerLives = 3;
int CGame::iLevel = 1;