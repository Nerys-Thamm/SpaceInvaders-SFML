#include "DebugWindow.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "EasySFML.h"
#include <algorithm>





DebugWindow::DebugWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(400, 400), "Space Invaders - Debug");
	
	font.loadFromFile("Resources/sansation.ttf");
	Options.push_back(sf::Text());
	Options[0].setFillColor(sf::Color::White);
	Options[0].setPosition(0, 0);
	Options[0].setFont(font);
	Options[0].setString("Score: Increase[\u2192] Decrease[\u2190]");
	Options.push_back(sf::Text());
	Options[1].setFillColor(sf::Color::White);
	Options[1].setPosition(0, 20);
	Options[1].setFont(font);
	Options[1].setString("Lives: Increase[\u2192] Decrease[\u2190]");
	Options.push_back(sf::Text());
	Options[2].setFillColor(sf::Color::White);
	Options[2].setPosition(0, 40);
	Options[2].setFont(font);
	Options[2].setString("Alien Speed: Increase[\u2192] Decrease[\u2190]");
	Options.push_back(sf::Text());
	Options[3].setFillColor(sf::Color::White);
	Options[3].setPosition(0, 60);
	Options[3].setFont(font);
	Options[3].setString("Bullet Speed: Increase[\u2192] Decrease[\u2190]");
	iCurrentIndex = 0;

}


DebugWindow::~DebugWindow()
{
	window->close();
	delete window;
}

void DebugWindow::Update(float _fDeltaTime)
{
	while (window->pollEvent(wEvent))
	{
		switch (wEvent.type)
		{
		case sf::Event::Closed:
			window->close();
			
			break;
		case sf::Event::KeyPressed:
			switch (wEvent.key.code)
			{
			case sf::Keyboard::Escape:
				CGame::bDebugMode = false;
				
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}

	}
	window->clear();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

	}
	
	for each (sf::Text text in Options)
	{
		window->draw(text);
	}
	window->display();

}



