#pragma once
#include "EasySFML.h"
// --------------------------------------------------------------------------------
/// <summary>
/// 
/// </summary>
// --------------------------------------------------------------------------------
class CLaser :
	public CGameObject
{
public:
	/// <summary>Hitbox of the Laser</summary>
	sf::RectangleShape laserRect;

	/// <summary>Coordinates of the Laser</summary>
	float fX, fY;
	
	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Constructor for Class: CLaser
	/// </para>
	/// </summary>
	/// <param name="_fX"><para>
	/// 			Type: float, Specifies X coord to spawn the Laser at
	/// 		</para></param>
	/// <param name="_fY"><para>
	/// 			Type: float, Specifies Y coord to spawn the Laser at
	/// 		</para></param>
	/// <returns></returns>
	// ********************************************************************************
	CLaser(float _fX, float _fY);

	// ********************************************************************************
	/// <summary>
	/// <para>
	/// Function name: FixedUpdate
	/// Function is part of Class: CLaser
	/// </para>
	/// </summary>
	// ********************************************************************************
	virtual void FixedUpdate();
};

