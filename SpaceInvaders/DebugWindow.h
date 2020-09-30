#pragma once
#include "EasySFML.h"
#include <vector>
class DebugWindow
	: CGameObject
{
public:
	DebugWindow();
	~DebugWindow();
	sf::RenderWindow* window;
	sf::Event wEvent;
	sf::Font font;
	std::vector<sf::Text> Options;
	int iCurrentIndex;
	virtual void Update(float _fDeltaTime);
	
};

