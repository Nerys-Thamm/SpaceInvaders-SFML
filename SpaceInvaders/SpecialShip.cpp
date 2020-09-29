#include "SpecialShip.h"



CSpecialShip::CSpecialShip()
{
	fDirectionMultiplier = 1;
	fX = 0;
	fY = 100;
	alienRect.setSize(sf::Vector2f(30, 20));
	alienRect.setOutlineThickness(2);
	alienRect.setOutlineColor(sf::Color::White);
	alienRect.setFillColor(sf::Color::Black);
	alienRect.setOrigin(sf::Vector2f(15, 10));
	alienRect.setPosition(sf::Vector2f(fX, fY));
	bIsAlive = true;
	Score = 300;
}


CSpecialShip::~CSpecialShip()
{
}
