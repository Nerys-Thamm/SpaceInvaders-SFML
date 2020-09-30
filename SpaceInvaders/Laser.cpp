#include "Laser.h"

CLaser::CLaser(float _fX, float _fY)
{
	fX = _fX; //set the Lasers coordinates
	fY = _fY;
	laserRect.setSize(sf::Vector2f(8, 40)); //configure the hitbox for the laser
	laserRect.setOutlineThickness(2);
	laserRect.setOutlineColor(sf::Color::White);
	laserRect.setFillColor(sf::Color::White);
	laserRect.setOrigin(sf::Vector2f(4, 8));

	laserRect.setPosition(sf::Vector2f(fX, fY)); //update the position of the hitbox
}

void CLaser::FixedUpdate()
{
	if (bIsEnabled) //If the object is enabled...
	{
		fY++; //Increase the Y coordinate by one
		laserRect.setPosition(sf::Vector2f(fX, fY)); //Update hitbox position
		CWindowUtilities::Draw(&laserRect); //prepare the laser to be drawn
	}
}
