#pragma once
#include "Sprites.h"
#include "EasySFML.h"
#include "Laser.h"

// --------------------------------------------------------------------------------
/// <summary>
/// 
/// </summary>
// --------------------------------------------------------------------------------
class CAlien : 
	private CGameObject
{

public:
	
	/// <summary></summary>
	sf::RectangleShape alienRect;

	/// <summary></summary>
	sf::Sprite alienSprite;

	/// <summary></summary>
	sf::Texture alienTexture;

	/// <summary></summary>
	float fX, fY;

	/// <summary></summary>
	float fDirectionMultiplier;

	/// <summary></summary>
	bool bIsAlive;

	/// <summary></summary>
	int Score;

	// ********************************************************************************
	/// <summary>
	/// 
	/// </summary>
	/// <param name="_fX"></param>
	/// <param name="_fY"></param>
	/// <param name="_score"></param>
	/// <returns></returns>
	// ********************************************************************************
	CAlien(float _fX, float _fY, int _score);

	// ********************************************************************************
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	// ********************************************************************************
	~CAlien();

	// ********************************************************************************
	/// <summary>
	/// 
	/// </summary>
	/// <param name="_fSpeedMult"></param>
	/// <returns></returns>
	// ********************************************************************************
	bool Move(float _fSpeedMult);

	// ********************************************************************************
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	// ********************************************************************************
	bool Descend();

	// ********************************************************************************
	/// <summary>
	/// 
	/// </summary>
	/// <param name="_rect"></param>
	/// <returns></returns>
	// ********************************************************************************
	bool CheckCollision(sf::RectangleShape _rect);

	// ********************************************************************************
	/// <summary>
	/// 
	/// </summary>
	// ********************************************************************************
	static void DeleteLasers();

	/// <summary></summary>
	static std::vector<CLaser*> Lasers;

	// ********************************************************************************
	/// <summary>
	/// 
	/// </summary>
	// ********************************************************************************
	virtual void FixedUpdate();

};

