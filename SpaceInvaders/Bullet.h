#pragma once
#include "Sprites.h"
#include "EasySFML.h"
class CBullet :
	private CGameObject
{
public:
	sf::RectangleShape bulletRect;
	float fX, fY;
	CBullet(float _fx);
	~CBullet();
	void Move(float _fDeltaTime);
	virtual void Update(float _fDeltaTime);
	
};

