#include "Player.h"
#include "Game.h"

CPlayer::CPlayer() //Constructor
{
	playerTexture.loadFromFile("Resources/Player.png"); //Load the players texture from resources...

	playerSprite.setTexture(playerTexture); //apply the texture to the players sprite
	playerSprite.setScale(sf::Vector2f(1.0f, 1.0f)); //Set the scale of the players sprite to be normal
	playerSprite.setOrigin(sf::Vector2f(40, 45)); //Set the origin of the players sprite to be in the middle

	playerRect.setSize(sf::Vector2f(80, 40)); //Set the size of the players hitbox
	playerRect.setOutlineThickness(2); //set the outline thickness
	playerRect.setOutlineColor(sf::Color::Red); //make the hitbox appear red when visible...
	playerRect.setFillColor(sf::Color::Black); //but with black fill so the red is an outline
	playerRect.setOrigin(sf::Vector2f(40, 20)); //set the origin of the hitbox to be in the middle

	fPlayerX = 400; //set the players starting position
	fPlayerY = 950;

	playerRect.setPosition(sf::Vector2f(fPlayerX, fPlayerY)); //Apply the position to the hitbox and sprite
	playerSprite.setPosition(sf::Vector2f(fPlayerX, fPlayerY));

	CGame::iPlayerLives = 3; //Make the player start with 3 lives
	CGame::iBulletSpeedMult = 1; 
}

void CPlayer::TryMove(float _fDeltaX)
{
	if ((fPlayerX + _fDeltaX < 50) || (fPlayerX + _fDeltaX > 750)) //If performing the movement would put the player outside of the designated range
	{
		return; //Cancel the movement
	}
	else //if not
	{
		fPlayerX += _fDeltaX; //apply the change in X position
		playerRect.setPosition(sf::Vector2f(fPlayerX, fPlayerY)); //update the hitbox and sprite with the new position
		playerSprite.setPosition(sf::Vector2f(fPlayerX, fPlayerY));
		return;
	}
}

void CPlayer::Update(float _fDeltaTime)
{
	//This frame...

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))//If the A key is being pressed...
	{
		float fDeltaX = -600 * _fDeltaTime; //Calculate change in X position based on time
		if ( fDeltaX + fPlayerX > 50) //If this movement wouldnt move the player out of bounds...
		{
			fPlayerX += fDeltaX; //apply the movement
		}
	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))//If the D key is being pressed...
	{
		float fDeltaX = 600 * _fDeltaTime; //Calculate change in X position based on time
		if (fDeltaX + fPlayerX < 750) //If this movement wouldnt move the player out of bounds...
		{
			fPlayerX += fDeltaX; //apply the movement
		}
	}

	playerRect.setPosition(sf::Vector2f(fPlayerX, fPlayerY)); //Update player hitbox and sprite with new position
	playerSprite.setPosition(sf::Vector2f(fPlayerX, fPlayerY));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (!bBulletExists))//if the S key is being pressed AND no Bullet exists...
	{
		pBullet = new CBullet(fPlayerX); //Create a bullet
		bBulletExists = true;
	}
	if (CGame::bDebugMode) //If the Game is in Debug mode...
	{
		CWindowUtilities::Draw(&playerRect); //Draw the players hitbox
	}
	CWindowUtilities::Draw(&playerSprite); //Then Draw the players sprite to the screen
	
}

bool CPlayer::CheckCollision(sf::RectangleShape lazer)
{
	if (lazer.getGlobalBounds().intersects(playerRect.getGlobalBounds()))//if the hitbox of the laser overlaps with the hitbox of the player...
	{
		CGame::iPlayerLives--; //Decrease player lives by one
		return true; //return true
	}
	else //if not...
	{
		return false; //return false instead
	}
}








