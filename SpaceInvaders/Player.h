////////////////////////////////////////////////////////////
//==========================================================
// Bachelor of Software Engineering                       
// Media Design School                                    
// Auckland                                               
// New Zealand                                            
//----------------------------------------------------------
// (c) 2020 Media Design School                           
//==========================================================
//   File Name  : Player.h                          
//----------------------------------------------------------
//  Description : Contains the definition and prototypes    
//  for the CPlayer class.                                                       
//                                                        
//                                                        
//----------------------------------------------------------
//    Author    : Nerys Thamm BSE20021                    
//----------------------------------------------------------
//    E-mail    : NerysThamm@gmail.com                    
//==========================================================
////////////////////////////////////////////////////////////

#pragma once
#include "Sprites.h"
#include "EasySFML.h"
#include "Bullet.h"

// --------------------------------------------------------------------------------
/// <summary>
/// The player-controlled CGameObject that the player uses to play the game
/// </summary>
// --------------------------------------------------------------------------------
class CPlayer :
	private CGameObject
{
public:
	/// <summary>Hitbox of the Player</summary>
	sf::RectangleShape playerRect;

	/// <summary>Current Coordinates of the player</summary>
	float fPlayerX, fPlayerY;

	/// <summary>The Players Sprite</summary>
	sf::Sprite playerSprite;

	/// <summary>The Texture used for the Players Sprite</summary>
	sf::Texture playerTexture;

	// ********************************************************************************
	/// <summary>
	/// Constructor for the CPlayer class
	/// </summary>
	/// <returns></returns>
	// ********************************************************************************
	CPlayer();

	// ********************************************************************************
	/// <summary>
	/// Moves the player on the X axis within a range
	/// </summary>
	/// <param name="_fDeltaX">Type: float, the positive or negative amount to change by</param>
	// ********************************************************************************
	void TryMove(float _fDeltaX);

	// ********************************************************************************
	/// <summary>
	/// Called every frame
	/// </summary>
	/// <param name="_fDeltaTime">Type: Float, Time since last frame</param>
	// ********************************************************************************
	virtual void Update(float _fDeltaTime);

	// ********************************************************************************
	/// <summary>
	/// Check if the provided shape is colliding with the player
	/// </summary>
	/// <param name="lazer">Type: SFML RectangleShape</param>
	/// <returns>True if a collision is occuring, false otherwise</returns>
	// ********************************************************************************
	bool CheckCollision(sf::RectangleShape lazer);

	/// <summary>Number of lives that the player has left</summary>
	int Lives = 3;

	/// <summary>Pointer to a CBullet, stores the players bullet when they fire it</summary>
	CBullet* pBullet = nullptr;

	/// <summary>Stores whether or not a bullet exists, as the player can only have one on screen at any one time</summary>
	bool bBulletExists = false;

	
};

