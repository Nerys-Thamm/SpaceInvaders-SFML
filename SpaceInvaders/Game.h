#pragma once
#include "DebugWindow.h"
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
	DebugWindow* debug = nullptr;
	int Start();
};

