#include "Bullet.h"
#include "Game.h"


// ********************************************************************************
/// <summary>
/// <para>
/// Constructor with Parameters for Class: CBullet
/// </para>
/// </summary>
/// <param name="_fX"><para>
/// Type: float, X coord to spawn the bullet at
/// </para></param>
/// <returns></returns>
// ********************************************************************************
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

// ********************************************************************************
/// <summary>
/// <para>
/// Destructor for Class: CBullet
/// </para>
/// </summary>
/// <returns></returns>
// ********************************************************************************
CBullet::~CBullet()
{
}

// ********************************************************************************
/// <summary>
/// <para>
/// Function name: Move
/// Function is part of Class: CBullet
/// </para>
/// </summary>
/// <param name="_fDeltaTime"><para>
/// Type: float, time since last frame
/// </para></param>
// ********************************************************************************
void CBullet::Move(float _fDeltaTime)
{
	fY -= 400 * _fDeltaTime * CGame::iBulletSpeedMult;
	bulletRect.setPosition(sf::Vector2f(fX, fY));
}

// ********************************************************************************
/// <summary>
/// <para>
/// Function name: Update
/// Function is part of Class: CBullet
/// </para>
/// </summary>
/// <param name="_fDeltaTime"><para>
/// Type: float, time since last frame
/// </para></param>
// ********************************************************************************
void CBullet::Update(float _fDeltaTime)
{
	Move(_fDeltaTime);
	CWindowUtilities::Draw(&bulletRect);
}


