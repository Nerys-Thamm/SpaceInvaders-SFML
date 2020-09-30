#pragma once
class CGame
{
public:
	static int score;
	static bool bDebugMode;
	static int iAlienSpeedMult;
	static int iBulletSpeedMult;
	static int iPlayerLives;
	static int iLevel;
	CGame();
	~CGame();
	int Start();
};

