#pragma once
#include "Sprites.h"
#include "EasySFML.h"
#include "Bullet.h"

class CPlayer :
	private CGameObject
{
public:
	sf::RectangleShape playerRect;
	float fPlayerX, fPlayerY;
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
	CPlayer();
	~CPlayer();
	void TryMove(float _fDeltaX);
	virtual void Update(float _fDeltaTime);
	bool CheckCollision(sf::RectangleShape lazer);
	int Lives = 3;
	CBullet* pBullet = nullptr;
	bool bBulletExists = false;
	
};

