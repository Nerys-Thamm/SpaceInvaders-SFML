#include "AlienManager.h"
#include "Game.h"

CAlienManager::CAlienManager()
{
	CGame::iAlienSpeedMult = 1;

	//Initialise the array of aliens
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			int score;
			if (i == 0) //Top row aliens are 30 point ones
			{
				score = 30;
			}
			else if (i < 3) //Middle row aliens are 20 point ones
			{
				score = 20;
			}
			else //Bottom row aliens are 10 point ones
			{
				score = 10;
			}
			AlienArr[i][j] = new CAlien((700 / 11)*j+50, (600 / 10)*i+200, score); //Create a new alien and set its position and score value before inserting into the array
		}
	}
	iRemainingAliens = 55; //Set remaining aliens to 55
}


CAlienManager::~CAlienManager()
{
	for (int i = 0; i < 5; i++)//Delete every alien in the Alien array
	{
		for (int j = 0; j < 11; j++)
		{
			delete AlienArr[i][j];
		}
	}
	delete SpecialShip;//Delete the Special Ship
}


bool CAlienManager::MoveAliens()
{
	bSideCollision = false;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (AlienArr[i][j]->Move(5/(iRemainingAliens+1)) == true && AlienArr[i][j]->bIsAlive) //Move every Alien. For each alien that is alive, check if it collided with the sides
			{
				bSideCollision = true;
			}
		}
	}
	if (bSideCollision) //If an alien  collided with the sides of the window this turn
	{
		return OnSideCollision(); //Tell all aliens to descend and return whether or not they reached the bottom of the screen
	}
	else
	{
		return false; //Return false
	}
}


bool CAlienManager::OnSideCollision()
{
	
	bool bHasInvaded = false;
	for (int i = 0; i < 5; i++) //For every alien
	{
		for (int j = 0; j < 11; j++)
		{
			if (AlienArr[i][j]->Descend()) //Tell the alien to descend
			{
				bHasInvaded = true; //Flag bHasInvaded as true if any aliens report reaching the bottom of the screen
			}
		}
	}
	return bHasInvaded; //Return whether or not an alien has reached the bottom of the screen
}


bool CAlienManager::CheckCollisions(sf::RectangleShape _rect)
{
	bool bHasHit = false;
	for (int i = 0; i < 5; i++) //For every alien
	{
		for (int j = 0; j < 11; j++)
		{
			if (AlienArr[i][j]->bIsAlive) //If the alien is alive
			{
				if (AlienArr[i][j]->CheckCollision(_rect)) //check if the aliens hitbox is colliding with the passed object
				{
					bHasHit = true;
					CGame::score += AlienArr[i][j]->Score; //if so increase the players score by an amount determined by the score value of the alien they hit
					iRemainingAliens--; //Decrease remaining aliens by 1
				}
			}
		}
	}
	if (SpecialShip != nullptr) //If a special ship exists
	{
		if (SpecialShip->CheckCollision(_rect)) //If the object collides with the hitbox of the special ship
		{
			bHasHit = true;
			CGame::score += SpecialShip->Score; //Award the player score for hitting the special bonus ship
			SpecialShip = nullptr;

		}
	}
	return bHasHit; //Return whether or not anything was hit
}


void CAlienManager::FixedUpdate()
{
	
	if ((rand() % 3000) + 1 == 1 && SpecialShip == nullptr) //Small chance of spawning a special ship if one does not already exist
	{
		SpecialShip = new CAlien(0, 50, 300);
	}
	if (SpecialShip != nullptr) //If the special ship does exist...
	{
		SpecialShip->Move(1); //Move the special ship
		if (SpecialShip->fX > 800) //If it reaches the side of the screen
		{
			SpecialShip->bIsAlive = false; //destroy the special ship
			
			SpecialShip = nullptr;
		}
	}
}


