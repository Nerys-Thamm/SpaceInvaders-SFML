#include "AlienManager.h"
#include "Game.h"


CAlienManager::CAlienManager()
{
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
}

void CAlienManager::MoveAliens()
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
		OnSideCollision();
	}
}

void CAlienManager::OnSideCollision()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			AlienArr[i][j]->Descend();
		}
	}
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
	MoveAliens();
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


