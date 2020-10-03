////////////////////////////////////////////////////////////
//==========================================================
// Bachelor of Software Engineering                       
// Media Design School                                    
// Auckland                                               
// New Zealand                                            
//----------------------------------------------------------
// (c) 2020 Media Design School                           
//==========================================================
//   File Name  : Alien.cpp                          
//----------------------------------------------------------
//  Description : Contains the implementation for the     
//  CAlien class.                                                      
//                                                        
//                                                        
//----------------------------------------------------------
//    Author    : Nerys Thamm BSE20021                    
//----------------------------------------------------------
//    E-mail    : NerysThamm@gmail.com                    
//==========================================================
////////////////////////////////////////////////////////////
#include "Alien.h"
#include "Game.h"


CAlien::CAlien(float _fX, float _fY, int _score = 0)
{
	//Load Texture depending on the type of alien
	if (_score <= 10)
	{
		alienTexture.loadFromFile("Resources/Alien1.png");//Bottom row aliens
	}
	else if (_score <= 20)
	{
		alienTexture.loadFromFile("Resources/Alien2.png");//Middle row aliens
	}
	else if(_score <= 30)
	{
		alienTexture.loadFromFile("Resources/Alien3.png");//Top row aliens
	}
	else
	{
		alienTexture.loadFromFile("Resources/Alien4.png");//Special bonus ship
	}
	fDirectionMultiplier = 1; //Move right initially

	fX = _fX; //Set Coords
	fY = _fY;

	alienSprite.setTexture(alienTexture); //Apply Texture to Sprite

	//Config Hitbox
	alienRect.setSize(sf::Vector2f(30, 20));
	alienRect.setOutlineThickness(2);
	alienRect.setOutlineColor(sf::Color::Red);
	alienRect.setFillColor(sf::Color::Black);
	alienRect.setOrigin(sf::Vector2f(15, 10));
	alienRect.setPosition(sf::Vector2f(fX, fY));

	//Config Sprite
	alienSprite.setScale(0.2f, 0.2f);
	alienSprite.setOrigin(sf::Vector2f(90, 60));
	alienSprite.setPosition(sf::Vector2f(fX, fY));

	//Initialise member variables
	bIsAlive = true;
	Score = _score;
}


bool CAlien::Move(float _fSpeedMult)
{
	fX += ((1+_fSpeedMult + CGame::iAlienSpeedMult + CGame::iLevel)  * fDirectionMultiplier)/8; //Change the X position by a positive or negative amount based on the level, speed, and direction multipliers
	alienRect.setPosition(sf::Vector2f(fX, fY)); //Update Hitbox and Sprite positions
	alienSprite.setPosition(sf::Vector2f(fX, fY));
	return ((fX <= 0) || (fX >= 800)); //Return true if the Alien hits either side of the screen, false otherwise
}


bool CAlien::CheckCollision(sf::RectangleShape _rect)
{
	if (_rect.getGlobalBounds().intersects(alienRect.getGlobalBounds())) //If the passed object is colliding with the Hitbox of the alien
	{
		bIsAlive = false; //Kill the alien
		return true; //Return true as a collision has occured
	}
	else //if not..
	{
		return false; //return false because a collision did not occur
	}
	
}


void CAlien::DeleteLasers()
{
	for each (CLaser* laser in Lasers) //Delete all laser instances in the Lasers vector, then clear the vector
	{
		delete laser;
	}
	Lasers.clear();
}


void CAlien::FixedUpdate()
{
	
	if (bIsAlive) //If the alien is alive
	{
		if (CGame::bDebugMode) //If the game is in debug mode
		{
			CWindowUtilities::Draw(&alienRect); //Draw the Hitbox
		}

		//regardless,

		CWindowUtilities::Draw(&alienSprite); //Draw the Sprite

		if ((rand() % 12000) + 1 == 1) //Small chance to spawn a CLaser at their position
		{
			Lasers.push_back(new CLaser(fX, fY));
		}

	}
}


bool CAlien::Descend()
{
	fDirectionMultiplier *= -1.0f; //Invert the aliens movement
	fY += 30; //move the alien down the screen
	alienRect.setPosition(sf::Vector2f(fX, fY)); //Update hitbox and sprite positions
	alienSprite.setPosition(sf::Vector2f(fX, fY));
	if (fY > 950) //If the alien reaches the bottom of the screen 
	{
		return true; //Return true
	}
	else //if not
	{
		return false; //return false
	}
}

std::vector<CLaser*> CAlien::Lasers;
