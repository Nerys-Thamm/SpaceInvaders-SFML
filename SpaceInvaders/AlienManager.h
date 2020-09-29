#pragma once
#include "Alien.h"
#include "EasySFML.h"

class CAlienManager :
	private CGameObject
{
public:
	CAlien* AlienArr[5][11];
	CAlien* SpecialShip = nullptr;
	int iRemainingAliens;
	bool bSideCollision;
	CAlienManager();
	~CAlienManager();
	void MoveAliens();
	void OnSideCollision();
	bool CheckCollisions(sf::RectangleShape _rect);
	virtual void FixedUpdate();
	
};

