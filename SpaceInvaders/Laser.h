#pragma once
#include "EasySFML.h"
class CLaser :
	public CGameObject
{
public:
	sf::RectangleShape laserRect;
	float fX, fY;
	
	CLaser(float _fX, float _fY);
	~CLaser();
	virtual void FixedUpdate();
};

