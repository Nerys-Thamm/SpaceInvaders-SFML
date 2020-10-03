////////////////////////////////////////////////////////////
//==========================================================
// Bachelor of Software Engineering                       
// Media Design School                                    
// Auckland                                               
// New Zealand                                            
//----------------------------------------------------------
// (c) 2020 Media Design School                           
//==========================================================
//   File Name  : AlienManager.h                          
//----------------------------------------------------------
//  Description : Contains the definition and prototypes    
//  for the CAlienManager class, which acts as a container                                                      
//  for CAlien.                                                      
//                                                        
//----------------------------------------------------------
//    Author    : Nerys Thamm BSE20021                    
//----------------------------------------------------------
//    E-mail    : NerysThamm@gmail.com                    
//==========================================================
////////////////////////////////////////////////////////////
#pragma once
#include "Alien.h"
#include "EasySFML.h"

// --------------------------------------------------------------------------------
/// <summary>
/// A container for CAlien
/// </summary>
// --------------------------------------------------------------------------------
class CAlienManager :
	private CGameObject
{
public:
	/// <summary>Array containing pointers to all spawned CAliens</summary>
	CAlien* AlienArr[5][11];

	/// <summary>Pointer that holds a Special bonus point ship when it spawns</summary>
	CAlien* SpecialShip = nullptr;

	/// <summary>The number of aliens remaining</summary>
	int iRemainingAliens;

	/// <summary>If an alien has collided with the side of the screen this frame</summary>
	bool bSideCollision;

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Constructor for Class: CAlienManager
	/// </para>
	/// </summary>
	/// <returns></returns>
	// ********************************************************************************
	CAlienManager();

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Destructor for Class: CAlienManager
	/// </para>
	/// </summary>
	/// <returns></returns>
	// ********************************************************************************
	~CAlienManager();

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Function name: MoveAliens
	/// Function is part of Class: CAlienManager
	/// </para>
	/// </summary>
	/// <returns>Value of type: bool</returns>
	// ********************************************************************************
	bool MoveAliens();

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Function name: OnSideCollision
	/// Function is part of Class: CAlienManager
	/// </para>
	/// </summary>
	/// <returns>Value of type: bool</returns>
	// ********************************************************************************
	bool OnSideCollision();

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Function name: CheckCollisions
	/// Function is part of Class: CAlienManager
	/// </para>
	/// </summary>
	/// <param name="_rect"><para>
	/// Type: sf::RectangleShape
	/// </para></param>
	/// <returns>Value of type: bool</returns>
	// ********************************************************************************
	bool CheckCollisions(sf::RectangleShape _rect);

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Function name: FixedUpdate
	/// Function is part of Class: CAlienManager
	/// </para>
	/// </summary>
	// ********************************************************************************
	virtual void FixedUpdate();
	
};

