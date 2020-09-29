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
	void Descend();
	bool CheckCollision(sf::RectangleShape _rect);
	static std::vector<CLaser*> Lasers;
	virtual void FixedUpdate();

};

