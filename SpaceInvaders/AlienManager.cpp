#include "AlienManager.h"
#include "Game.h"

// ********************************************************************************
/// <summary>
/// <para>
/// Constructor for Class: CAlienManager
/// </para>
/// </summary>
/// <returns></returns>
// ********************************************************************************
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

// ********************************************************************************
/// <summary>
/// <para>
/// Destructor for Class: CAlienManager
/// </para>
/// </summary>
/// <returns></returns>
// ********************************************************************************
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

// ********************************************************************************
/// <summary>
/// <para>
/// Function name: MoveAliens
/// Function is part of Class: CAlienManager
/// </para>
/// </summary>
/// <returns>Value of type: bool</returns>
// ********************************************************************************
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

// ********************************************************************************
/// <summary>
/// <para>
/// Function name: OnSideCollision
/// Function is part of Class: CAlienManager
/// </para>
/// </summary>
/// <returns>Value of type: bool</returns>
// ********************************************************************************
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

// ********************************************************************************
/// <summary>
/// <para>
/// Function name: CheckCollisions
/// Function is part of Class: CAlienManager
/// </para>
/// </summary>
/// <param name="_rect"><para>
/// Type: sf::RectangleShape
/// </para></param>
/// <returns>Value of type: bool</returns>
// ********************************************************************************
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

// ********************************************************************************
/// <summary>
/// <para>
/// Function name: FixedUpdate
/// Function is part of Class: CAlienManager
/// </para>
/// </summary>
// ********************************************************************************
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


