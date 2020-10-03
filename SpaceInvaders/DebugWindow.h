////////////////////////////////////////////////////////////
//==========================================================
// Bachelor of Software Engineering                       
// Media Design School                                    
// Auckland                                               
// New Zealand                                            
//----------------------------------------------------------
// (c) 2020 Media Design School                           
//==========================================================
//   File Name  : DebugWindow.h                          
//----------------------------------------------------------
//  Description : Contains the definition and prototypes    
//  for the DebugWindow class.                                                       
//                                                        
//                                                        
//----------------------------------------------------------
//    Author    : Nerys Thamm BSE20021                    
//----------------------------------------------------------
//    E-mail    : NerysThamm@gmail.com                    
//==========================================================
////////////////////////////////////////////////////////////
#pragma once
#include "EasySFML.h"
#include <vector>
// --------------------------------------------------------------------------------
/// <summary>
/// The Debug Window that contains a menu with which the user can alter game variables during run time
/// </summary>
// --------------------------------------------------------------------------------
class DebugWindow
	: CGameObject
{
public:
	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Constructor for Class: DebugWindow
	/// </para>
	/// </summary>
	/// <returns></returns>
	// ********************************************************************************
	DebugWindow();

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Destructor for Class: DebugWindow
	/// </para>
	/// </summary>
	/// <returns></returns>
	// ********************************************************************************
	~DebugWindow();

	/// <summary>The Debug Window</summary>
	sf::RenderWindow* window;

	/// <summary>The Event Stack for the Debug Window</summary>
	sf::Event wEvent;

	/// <summary>The Font to be used in the Debug Window</summary>
	sf::Font font;

	// --------------------------------------------------------------------------------
	/// <summary>
	/// SFML text containing instructions on how to use the Debug menu
	/// </summary>
	// --------------------------------------------------------------------------------
	sf::Text instructions;

	/// <summary>A vector of menu options as SFML text</summary>
	std::vector<sf::Text> Options;

	/// <summary>The index of the current option selection in the Debug Menu</summary>
	int iCurrentIndex;

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Function name: Update
	/// Function is part of Class: DebugWindow
	/// Called every frame, this method is used to handle input to the Debug Window and to draw the Debug window
	/// </para>
	/// </summary>
	/// <param name="_fDeltaTime">Type: Float, the time since the last frame<para>
	/// 
	/// </para></param>
	// ********************************************************************************
	virtual void Update(float _fDeltaTime);
	
};

