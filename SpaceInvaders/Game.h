#pragma once
#include "DebugWindow.h"
// --------------------------------------------------------------------------------
/// <summary>
/// The class that stores Game variables and houses the logic for the Game loop
/// </summary>
// --------------------------------------------------------------------------------
class CGame
{
public:
	
	/// <summary>The Players Current Score</summary>
	static int score;

	/// <summary>Stores whether Debug Mode is On or Off</summary>
	static bool bDebugMode;

	/// <summary>Stores the speed multiplier for Alien movement, as editable via the Debug Menu</summary>
	static int iAlienSpeedMult;

	/// <summary>Stores the speed multiplier for Bullet movement, as editable via the Debug Menu</summary>
	static int iBulletSpeedMult;

	/// <summary>Stores the amount of lives the player has left, as editable via the Debus Menu</summary>
	static int iPlayerLives;

	/// <summary>Stores the current level, i.e the number of waves of aliens the player has defeated. This is used as a multiplier for alien speed to scale difficulty.</summary>
	static int iLevel;


	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Constructor for Class: CGame
	/// </para>
	/// </summary>
	/// <returns></returns>
	// ********************************************************************************
	CGame();

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Destructor for Class: CGame
	/// </para>
	/// </summary>
	/// <returns></returns>
	// ********************************************************************************
	~CGame();

	/// <summary>Stores the debug window when it is opened, remains nullptr otherwise</summary>
	DebugWindow* debug = nullptr;

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Function name: Start
	/// Function is part of Class: CGame
	/// Opens the Game window and begins the main game loop
	/// </para>
	/// </summary>
	/// <returns>Value of type: int, the players score apon the game window closing</returns>
	// ********************************************************************************
	int Start();
};

