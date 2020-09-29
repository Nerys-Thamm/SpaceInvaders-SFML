#include "Alien.h"




CAlien::CAlien(float _fX, float _fY, int _score = 0)
{
	
	fDirectionMultiplier = 1;
	fX = _fX;
	fY = _fY;
	alienRect.setSize(sf::Vector2f(30, 20));
	alienRect.setOutlineThickness(2);
	alienRect.setOutlineColor(sf::Color::White);
	alienRect.setFillColor(sf::Color::Black);
	alienRect.setOrigin(sf::Vector2f(15, 10));
	alienRect.setPosition(sf::Vector2f(fX, fY));
	bIsAlive = true;
	Score = _score;
}


CAlien::~CAlien()
{
}

bool CAlien::Move(float _fSpeedMult)
{
	fX += (1+_fSpeedMult) * fDirectionMultiplier;
	alienRect.setPosition(sf::Vector2f(fX, fY));
	return ((fX <= 0) || (fX >= 800));
	
		
	
}

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

void CAlien::FixedUpdate()
{
	
	if (bIsAlive)
	{
		CWindowUtilities::Draw(&alienRect);
		if ((rand() % 3000) + 1 == 1)
		{
			Lasers.push_back(new CLaser(fX, fY));
		}

	}
}

void CAlien::Descend()
{
	fDirectionMultiplier *= -1.0f;
	fY += 30;
	alienRect.setPosition(sf::Vector2f(fX, fY));
}

std::vector<CLaser*> CAlien::Lasers;
