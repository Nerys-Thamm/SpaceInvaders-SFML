#pragma once
#include "Sprites.h"
#include "EasySFML.h"
#include "Laser.h"

class CAlien : 
	private CGameObject
{

public:
	
	sf::RectangleShape alienRect;
	float fX, fY;
	float fDirectionMultiplier;
	bool bIsAlive;
	int Score;
	CAlien(float _fX, float _fY, int _score);
	~CAlien();
	bool Move(float _fSpeedMult);
	bool Descend();
	bool CheckCollision(sf::RectangleShape _rect);
	static void DeleteLasers();
	static std::vector<CLaser*> Lasers;
	virtual void FixedUpdate();

};

