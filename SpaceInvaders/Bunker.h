#pragma once
#include "Sprites.h"
#include "EasySFML.h"

struct BunkerBlock
{
	sf::RectangleShape rect;
	bool bIsDestroyed;
};
class CBunker
	: CGameObject
{
public:
	BunkerBlock BlockArr[5][3];
	
	float fX, fY;
	CBunker(float _fX, float _fY);
	~CBunker();
	bool CheckCollisions(sf::RectangleShape _rect);
	virtual void FixedUpdate();
};

