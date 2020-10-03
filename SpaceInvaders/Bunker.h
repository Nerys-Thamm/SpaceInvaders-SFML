////////////////////////////////////////////////////////////
//==========================================================
// Bachelor of Software Engineering                       
// Media Design School                                    
// Auckland                                               
// New Zealand                                            
//----------------------------------------------------------
// (c) 2020 Media Design School                           
//==========================================================
//   File Name  : Bunker.h                          
//----------------------------------------------------------
//  Description : Contains the definition and prototypes    
//  for the CBunker class, which acts as a container for                                                      
//  the CBunker struct, also defined here.                                                      
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

// --------------------------------------------------------------------------------
/// <summary>
/// A structure that stores a hitbox and whether it has been destroyed, acting as the blocks the CBunkers are constructed from
/// </summary>
// --------------------------------------------------------------------------------
struct BunkerBlock
{
	/// <summary>The hitbox of the block</summary>
	sf::RectangleShape rect;

	/// <summary>Whether the block has been destroyed</summary>
	bool bIsDestroyed;
};
// --------------------------------------------------------------------------------
/// <summary>
/// Instances of CBunker are used as the 4 bunkers protecting the player from alien lasers
/// </summary>
// --------------------------------------------------------------------------------
class CBunker
	: CGameObject
{
public:
	/// <summary>An array that stores 15 bunker blocks</summary>
	BunkerBlock BlockArr[5][3];
	
	/// <summary>The Coordinates of the bunker</summary>
	float fX, fY;

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Constructor for Class: CBunker
	/// </para>
	/// </summary>
	/// <param name="_fX">Type: Float, X coord to spawn the bunker at</param>
	/// <param name="_fY">Type: Float, Y coord to spawn the bunker at</param>
	/// <returns></returns>
	// ********************************************************************************
	CBunker(float _fX, float _fY);

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Function name: CheckCollisions
	/// Function is part of Class: CBunker
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
	/// Function is part of Class: CBunker
	/// </para>
	/// </summary>
	// ********************************************************************************
	virtual void FixedUpdate();
};

