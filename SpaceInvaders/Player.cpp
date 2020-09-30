#include "Player.h"
#include "Game.h"



// ********************************************************************************
/// <summary>
/// Constructor for the CPlayer class
/// </summary>
/// <returns></returns>
// ********************************************************************************
CPlayer::CPlayer()
{
	playerTexture.loadFromFile("Resources/Player.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setScale(sf::Vector2f(1.0f, 1.0f));
	playerSprite.setOrigin(sf::Vector2f(40, 45));
	playerRect.setSize(sf::Vector2f(80, 40));
	playerRect.setOutlineThickness(2);
	playerRect.setOutlineColor(sf::Color::Red);
	playerRect.setFillColor(sf::Color::Black);
	playerRect.setOrigin(sf::Vector2f(40, 20));
	fPlayerX = 400;
	fPlayerY = 950;
	playerRect.setPosition(sf::Vector2f(fPlayerX, fPlayerY));
	playerSprite.setPosition(sf::Vector2f(fPlayerX, fPlayerY));
	CGame::iPlayerLives = 3;
	CGame::iBulletSpeedMult = 1;
}


// ********************************************************************************
/// <summary>
/// Destructor for the CPlayer class
/// </summary>
/// <returns></returns>
// ********************************************************************************
CPlayer::~CPlayer()
{
}

// ********************************************************************************
/// <summary>
/// Moves the player on the X axis within a range
/// </summary>
/// <param name="_fDeltaX"></param>
// ********************************************************************************
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
		playerSprite.setPosition(sf::Vector2f(fPlayerX, fPlayerY));
		return;
	}
}

// ********************************************************************************
/// <summary>
/// Called every frame
/// </summary>
/// <param name="_fDeltaTime">Type: Float, Time since last frame</param>
// ********************************************************************************
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
	playerSprite.setPosition(sf::Vector2f(fPlayerX, fPlayerY));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (!bBulletExists))
	{
		pBullet = new CBullet(fPlayerX);
		bBulletExists = true;
	}
	if (CGame::bDebugMode)
	{
		CWindowUtilities::Draw(&playerRect);
	}
	CWindowUtilities::Draw(&playerSprite);
	
}

// ********************************************************************************
/// <summary>
/// Check if the provided shape is colliding with the player
/// </summary>
/// <param name="lazer">Type: SFML RectangleShape</param>
/// <returns>True if a collision is occuring, false otherwise</returns>
// ********************************************************************************
bool CPlayer::CheckCollision(sf::RectangleShape lazer)
{
	if (lazer.getGlobalBounds().intersects(playerRect.getGlobalBounds()))
	{
		CGame::iPlayerLives--;
		return true;
	}
	else
	{
		return false;
	}
}








