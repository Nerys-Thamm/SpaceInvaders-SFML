#include "AlienManager.h"
#include "Game.h"

CAlienManager::CAlienManager()
{
	CGame::iAlienSpeedMult = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			int score;
			if (i == 0)
			{
				score = 30;
			}
			else if (i < 3)
			{
				score = 20;
			}
			else
			{
				score = 10;
			}
			AlienArr[i][j] = new CAlien((700 / 11)*j+50, (600 / 10)*i+200, score);
		}
	}
	iRemainingAliens = 55;
}


CAlienManager::~CAlienManager()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			delete AlienArr[i][j];
		}
	}
	delete SpecialShip;
}


bool CAlienManager::MoveAliens()
{
	bSideCollision = false;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (AlienArr[i][j]->Move(5/(iRemainingAliens+1)) == true && AlienArr[i][j]->bIsAlive)
			{
				bSideCollision = true;
			}
		}
	}
	if (bSideCollision)
	{
		return OnSideCollision();
	}
	else
	{
		return false;
	}
}


bool CAlienManager::OnSideCollision()
{
	bool bHasInvaded = false;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (AlienArr[i][j]->Descend())
			{
				bHasInvaded = true;
			}
		}
	}
	return bHasInvaded;
}


bool CAlienManager::CheckCollisions(sf::RectangleShape _rect)
{
	bool bHasHit = false;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (AlienArr[i][j]->bIsAlive)
			{
				if (AlienArr[i][j]->CheckCollision(_rect))
				{
					bHasHit = true;
					CGame::score += AlienArr[i][j]->Score;
					iRemainingAliens--;
				}
			}
		}
	}
	if (SpecialShip != nullptr)
	{
		if (SpecialShip->CheckCollision(_rect))
		{
			bHasHit = true;
			CGame::score += SpecialShip->Score;
			SpecialShip = nullptr;

		}
	}
	return bHasHit;
}


void CAlienManager::FixedUpdate()
{
	
	if ((rand() % 3000) + 1 == 1 && SpecialShip == nullptr)
	{
		SpecialShip = new CAlien(0, 50, 300);
	}
	if (SpecialShip != nullptr)
	{
		SpecialShip->Move(1);
		if (SpecialShip->fX > 800)
		{
			SpecialShip->bIsAlive = false;
			
			SpecialShip = nullptr;
		}
	}
}


