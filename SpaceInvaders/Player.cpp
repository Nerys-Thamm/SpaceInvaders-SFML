#include "Player.h"



CPlayer::CPlayer()
{
	
	playerRect.setSize(sf::Vector2f(80, 40));
	playerRect.setOutlineThickness(2);
	playerRect.setOutlineColor(sf::Color::White);
	playerRect.setFillColor(sf::Color::Black);
	playerRect.setOrigin(sf::Vector2f(40, 20));
	fPlayerX = 400;
	fPlayerY = 950;
	playerRect.setPosition(sf::Vector2f(fPlayerX, fPlayerY));
	Lives = 3;
}


CPlayer::~CPlayer()
{
}

void CPlayer::TryMove(float _fDeltaX)
{
	if ((fPlayerX + _fDeltaX < 50) || (fPlayerX + _fDeltaX > 750))
	{
		return;
	}
	else
	{
		fPlayerX += _fDeltaX;
		playerRect.setPosition(sf::Vector2f(fPlayerX, fPlayerY));
		return;
	}
}

void CPlayer::Update(float _fDeltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		float fDeltaX = -600 * _fDeltaTime;
		if ( fDeltaX + fPlayerX > 50)
		{
			fPlayerX += fDeltaX;
		}
	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		float fDeltaX = 600 * _fDeltaTime;
		if (fDeltaX + fPlayerX < 750)
		{
			fPlayerX += fDeltaX;
		}
	}
	playerRect.setPosition(sf::Vector2f(fPlayerX, fPlayerY));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (!bBulletExists))
	{
		pBullet = new CBullet(fPlayerX);
		bBulletExists = true;
	}
	CWindowUtilities::Draw(&playerRect);
	
}

bool CPlayer::CheckCollision(sf::RectangleShape lazer)
{
	if (lazer.getGlobalBounds().intersects(playerRect.getGlobalBounds()))
	{
		Lives--;
		return true;
	}
	else
	{
		return false;
	}
}








