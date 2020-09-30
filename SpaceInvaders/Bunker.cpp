#include "Bunker.h"

CBunker::CBunker(float _fX, float _fY)
{
	fX = _fX; //set Coords
	fY = _fY;

	//initialise all the bunker blocks in the correct position
	int iYMod;
	for (int i = 0; i < 5; i++)
	{
		if (i == 0 || i == 4)//make the bunker blocks in the 1st and 5th column lower to give the classic shape
		{
			iYMod = 1;
		}
		else
		{
			iYMod = 0;
		}
		for (int j = 0; j < 3; j++) //fill the array
		{
			
			BlockArr[i][j].rect.setSize(sf::Vector2f(20, 20));
			BlockArr[i][j].rect.setOutlineThickness(1);
			BlockArr[i][j].rect.setOutlineColor(sf::Color::Green);
			BlockArr[i][j].rect.setFillColor(sf::Color::Green);
			BlockArr[i][j].rect.setOrigin(sf::Vector2f(10, 10));
			BlockArr[i][j].rect.setPosition(sf::Vector2f(fX+(i*20), fY+((j+iYMod)*20)));
			BlockArr[i][j].bIsDestroyed = false;
		}
	}
}

bool CBunker::CheckCollisions(sf::RectangleShape _rect)
{
	bool bHasHit = false;
	for (int i = 0; i < 5; i++)//for every bunker block
	{
		for (int j = 0; j < 3; j++)
		{
			if (!BlockArr[i][j].bIsDestroyed)//if its not destroyed
			{
				if (_rect.getGlobalBounds().intersects(BlockArr[i][j].rect.getGlobalBounds())) //Check if its hitbox intersects with the passed in hitbox
				{
					BlockArr[i][j].bIsDestroyed = true; //if so, mark the bunker block as destroyed and flag the hit
					bHasHit = true;
				}
				
			}
		}
	}
	return bHasHit; //Return whether or not the passed in hitbox collided
}


void CBunker::FixedUpdate()
{
	for (int i = 0; i < 5; i++) //for every bunker block
	{

		for (int j = 0; j < 3; j++)
		{
			if (!BlockArr[i][j].bIsDestroyed) //if it isnt destroyed
			{
				CWindowUtilities::Draw(&BlockArr[i][j].rect); //add it to the list of objects to be drawn to the screen
			}
		}
	}
}
