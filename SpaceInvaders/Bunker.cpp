#include "Bunker.h"



CBunker::CBunker(float _fX, float _fY)
{
	fX = _fX;
	fY = _fY;
	int iYMod;
	for (int i = 0; i < 5; i++)
	{
		if (i == 0 || i == 4)
		{
			iYMod = 1;
		}
		else
		{
			iYMod = 0;
		}
		for (int j = 0; j < 3; j++)
		{
			
			BlockArr[i][j].rect.setSize(sf::Vector2f(20, 20));
			BlockArr[i][j].rect.setOutlineThickness(1);
			BlockArr[i][j].rect.setOutlineColor(sf::Color::White);
			BlockArr[i][j].rect.setFillColor(sf::Color::White);
			BlockArr[i][j].rect.setOrigin(sf::Vector2f(10, 10));
			BlockArr[i][j].rect.setPosition(sf::Vector2f(fX+(i*20), fY+((j+iYMod)*20)));
			BlockArr[i][j].bIsDestroyed = false;
		}
	}
}


CBunker::~CBunker()
{
}

bool CBunker::CheckCollisions(sf::RectangleShape _rect)
{
	bool bHasHit = false;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!BlockArr[i][j].bIsDestroyed)
			{
				if (_rect.getGlobalBounds().intersects(BlockArr[i][j].rect.getGlobalBounds()))
				{
					BlockArr[i][j].bIsDestroyed = true;
					bHasHit = true;
				}
				
			}
		}
	}
	return bHasHit;
}
