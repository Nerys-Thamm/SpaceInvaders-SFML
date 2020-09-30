#include "Bullet.h"
#include "Game.h"



CBullet::CBullet(float _fX)
{
	fX = _fX;
	fY = 950;
	bulletRect.setSize(sf::Vector2f(1, 16));
	bulletRect.setOutlineThickness(2);
	bulletRect.setOutlineColor(sf::Color::White);
	bulletRect.setFillColor(sf::Color::White);
	bulletRect.setOrigin(sf::Vector2f(1, 2));
	bulletRect.setPosition(sf::Vector2f(fX, fY));
}


CBullet::~CBullet()
{
}

void CBullet::Move(float _fDeltaTime)
{
	fY -= 400 * _fDeltaTime * CGame::iBulletSpeedMult;
	bulletRect.setPosition(sf::Vector2f(fX, fY));
}

void CBullet::Update(float _fDeltaTime)
{
	Move(_fDeltaTime);
	CWindowUtilities::Draw(&bulletRect);
}


