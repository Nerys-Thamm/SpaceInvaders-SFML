#include "Laser.h"



CLaser::CLaser(float _fX, float _fY)
{
	fX = _fX;
	fY = _fY;
	laserRect.setSize(sf::Vector2f(8, 16));
	laserRect.setOutlineThickness(2);
	laserRect.setOutlineColor(sf::Color::White);
	laserRect.setFillColor(sf::Color::Black);
	laserRect.setOrigin(sf::Vector2f(4, 8));
	laserRect.setPosition(sf::Vector2f(fX, fY));
}


CLaser::~CLaser()
{
}

void CLaser::FixedUpdate()
{
	if (bIsEnabled)
	{
		fY += 1;
		laserRect.setPosition(sf::Vector2f(fX, fY));
		CWindowUtilities::Draw(&laserRect);
	}
}