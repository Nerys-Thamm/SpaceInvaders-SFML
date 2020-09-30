#pragma once
#include "Sprites.h"
#include "EasySFML.h"
#include "Laser.h"

// --------------------------------------------------------------------------------
/// <summary>
/// Instances of CAlien form the Alien invaders the player aims to defeat
/// </summary>
// --------------------------------------------------------------------------------
class CAlien : 
	private CGameObject
{

public:
	
	/// <summary>The Hitbox of the Alien</summary>
	sf::RectangleShape alienRect;

	/// <summary>The Sprite of the Alien</summary>
	sf::Sprite alienSprite;

	/// <summary>The Texture of the Alien</summary>
	sf::Texture alienTexture;

	/// <summary>Coordinates of the Alien</summary>
	float fX, fY;

	/// <summary>Direction Multiplier: Determines whether movement is positive(*1) or negative(*-1)</summary>
	float fDirectionMultiplier;

	/// <summary>Stores if the Alien is alive</summary>
	bool bIsAlive;

	/// <summary>Stores the number of points to award to the player when the alien is destroyed</summary>
	int Score;

	// ********************************************************************************
	/// <summary>
	/// Constructor for the CAlien class
	/// </summary>
	/// <param name="_fX"></param>
	/// <param name="_fY"></param>
	/// <param name="_score"></param>
	/// <returns></returns>
	// ********************************************************************************
	CAlien(float _fX, float _fY, int _score);

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Function name: Move
	/// Function is part of Class: CAlien
	/// </para>
	/// </summary>
	/// <param name="_fSpeedMult"><para>
	/// Type: float
	/// </para></param>
	/// <returns>Value of type: bool</returns>
	// ********************************************************************************
	bool Move(float _fSpeedMult);

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Function name: Descend
	/// Function is part of Class: CAlien
	/// </para>
	/// </summary>
	/// <returns>Value of type: bool</returns>
	// ********************************************************************************
	bool Descend();

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Function name: CheckCollision
	/// Function is part of Class: CAlien
	/// </para>
	/// </summary>
	/// <param name="_rect"><para>
	/// Type: sf::RectangleShape
	/// </para></param>
	/// <returns>Value of type: bool</returns>
	// ********************************************************************************
	bool CheckCollision(sf::RectangleShape _rect);

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Function name: DeleteLasers
	/// Function is part of Class: CAlien
	/// </para>
	/// </summary>
	// ********************************************************************************
	static void DeleteLasers();

	/// <summary>Stores pointers to the Lasers the Alien has spawned</summary>
	static std::vector<CLaser*> Lasers;

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Function name: FixedUpdate
	/// Function is part of Class: CAlien
	/// </para>
	/// </summary>
	// ********************************************************************************
	virtual void FixedUpdate();

};

