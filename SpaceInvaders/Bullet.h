#pragma once
#include "Sprites.h"
#include "EasySFML.h"
// --------------------------------------------------------------------------------
/// <summary>
/// Instances of CBullet are created by the player's weapon to destroy aliens
/// </summary>
// --------------------------------------------------------------------------------
class CBullet :
	private CGameObject
{
public:
	/// <summary>Hitbox of the bullet</summary>
	sf::RectangleShape bulletRect;

	/// <summary>Coordinates of the bullet</summary>
	float fX, fY;

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
	CBullet(float _fx);

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
	virtual void Update(float _fDeltaTime);
	
};

