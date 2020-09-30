#include "Alien.h"
#include "Game.h"




// ********************************************************************************
/// <summary>
/// Constructor for the CAlien class
/// </summary>
/// <param name="_fX"></param>
/// <param name="_fY"></param>
/// <param name="_score"></param>
/// <returns></returns>
// ********************************************************************************
CAlien::CAlien(float _fX, float _fY, int _score = 0)
{
	if (_score <= 10)
	{
		alienTexture.loadFromFile("Resources/Alien1.png");
	}
	else if (_score <= 20)
	{
		alienTexture.loadFromFile("Resources/Alien2.png");
	}
	else if(_score <= 30)
	{
		alienTexture.loadFromFile("Resources/Alien3.png");
	}
	else
	{
		alienTexture.loadFromFile("Resources/Alien4.png");
	}
	fDirectionMultiplier = 1;
	fX = _fX;
	fY = _fY;
	alienSprite.setTexture(alienTexture);
	alienRect.setSize(sf::Vector2f(30, 20));
	alienRect.setOutlineThickness(2);
	alienRect.setOutlineColor(sf::Color::Red);
	alienRect.setFillColor(sf::Color::Black);
	alienRect.setOrigin(sf::Vector2f(15, 10));
	alienRect.setPosition(sf::Vector2f(fX, fY));
	alienSprite.setScale(0.2f, 0.2f);
	alienSprite.setOrigin(sf::Vector2f(90, 60));
	alienSprite.setPosition(sf::Vector2f(fX, fY));
	bIsAlive = true;
	Score = _score;
}


// ********************************************************************************
/// <summary>
/// <para>
/// Function name: Move
/// Function is part of Class: CAlien
/// </para>
/// </summary>
/// <param name="_fSpeedMult"><para>
/// Type: float
/// </para></param>
/// <returns>Value of type: bool</returns>
// ********************************************************************************
bool CAlien::Move(float _fSpeedMult)
{
	fX += ((1+_fSpeedMult + CGame::iAlienSpeedMult + CGame::iLevel)  * fDirectionMultiplier)/8;
	alienRect.setPosition(sf::Vector2f(fX, fY));
	alienSprite.setPosition(sf::Vector2f(fX, fY));
	return ((fX <= 0) || (fX >= 800));
	
		
	
}
// ********************************************************************************
/// <summary>
/// <para>
/// Function name: CheckCollision
/// Function is part of Class: CAlien
/// </para>
/// </summary>
/// <param name="_rect"><para>
/// Type: sf::RectangleShape
/// </para></param>
/// <returns>Value of type: bool</returns>
// ********************************************************************************
bool CAlien::CheckCollision(sf::RectangleShape _rect)
{
	if (_rect.getGlobalBounds().intersects(alienRect.getGlobalBounds()))
	{
		bIsAlive = false;
		return true;
	}
	else 
	{
		return false;
	}
	
}
// ********************************************************************************
/// <summary>
/// <para>
/// Function name: DeleteLasers
/// Function is part of Class: CAlien
/// </para>
/// </summary>
// ********************************************************************************
void CAlien::DeleteLasers()
{
	for each (CLaser* laser in Lasers)
	{
		delete laser;
	}
	Lasers.clear();
}
// ********************************************************************************
/// <summary>
/// <para>
/// Function name: FixedUpdate
/// Function is part of Class: CAlien
/// </para>
/// </summary>
// ********************************************************************************
void CAlien::FixedUpdate()
{
	
	if (bIsAlive)
	{
		if (CGame::bDebugMode)
		{
			CWindowUtilities::Draw(&alienRect);
		}
		CWindowUtilities::Draw(&alienSprite);

		if ((rand() % 12000) + 1 == 1)
		{
			Lasers.push_back(new CLaser(fX, fY));
		}

	}
}

// ********************************************************************************
/// <summary>
/// <para>
/// Function name: Descend
/// Function is part of Class: CAlien
/// </para>
/// </summary>
/// <returns>Value of type: bool</returns>
// ********************************************************************************
bool CAlien::Descend()
{
	fDirectionMultiplier *= -1.0f;
	fY += 30;
	alienRect.setPosition(sf::Vector2f(fX, fY));
	alienSprite.setPosition(sf::Vector2f(fX, fY));
	if (fY > 950)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::vector<CLaser*> CAlien::Lasers;
