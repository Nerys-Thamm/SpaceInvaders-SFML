#include <SFML/Graphics.hpp>
#include "player.h"
#include "Alienmanager.h"
#include "Bullet.h"
#include "Bunker.h"
#include <string>
#include "EasySFML.h"
#include <algorithm>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 1000), "Space Invaders - Nerys Thamm");
	srand(764387493475);
	sf::Event event;
	
	

	
	
	int iScore = 0;
	bool bInMenu = true;
	bool bIsPlaying = false;
	sf::Font font;
	font.loadFromFile("Resources/sansation.ttf");
	sf::Text title;
	sf::Text prompt;
	title.setPosition(300, 400);
	title.setFillColor(sf::Color::White);
	title.setFont(font);
	title.setString("Space Invaders");
	prompt.setPosition(350, 500);
	prompt.setFillColor(sf::Color::White);
	prompt.setFont(font);
	prompt.setString("Press Spacebar to play");

	CGame game;
	
	
	while (window.isOpen())
	{

		while (bInMenu)
		{
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
				}
				

			}
			
			window.clear();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				game.Start();
			}
			else
			{
				window.draw(title);
				window.draw(prompt);
				window.display();
			}


		}


		
	}
	return 0;
}