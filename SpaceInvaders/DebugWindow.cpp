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
	instructions.setFillColor(sf::Color::White);
	instructions.setPosition(5, 0);
	instructions.setFont(font);
	instructions.setString("            <Arrow Keys:> \n                        UP\n                        [^]\nDecrease{[<][v][>]}Increase\n                    DOWN");
	Options.push_back(sf::Text());
	Options[0].setFillColor(sf::Color::White);
	Options[0].setPosition(5, 240);
	Options[0].setFont(font);
	Options[0].setString("Score: ");
	Options.push_back(sf::Text());
	Options[1].setFillColor(sf::Color::White);
	Options[1].setPosition(5, 280);
	Options[1].setFont(font);
	Options[1].setString("Lives: ");
	Options.push_back(sf::Text());
	Options[2].setFillColor(sf::Color::White);
	Options[2].setPosition(5, 320);
	Options[2].setFont(font);
	Options[2].setString("Alien Speed: ");
	Options.push_back(sf::Text());
	Options[3].setFillColor(sf::Color::White);
	Options[3].setPosition(5, 360);
	Options[3].setFont(font);
	Options[3].setString("Bullet Speed: ");
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
			case sf::Keyboard::Up:
				if (iCurrentIndex > 0)
				{
					iCurrentIndex--;
				}
				else
				{
					iCurrentIndex = 3;
				}
				break;
			case sf::Keyboard::Down:
				if (iCurrentIndex < 3)
				{
					iCurrentIndex++;
				}
				else
				{
					iCurrentIndex = 0;
				}

				break;
			case sf::Keyboard::Left:
				switch (iCurrentIndex)
				{
				case 0:
					if (CGame::score >= 10)
					{
						CGame::score -= 10;
					}
					else
					{
						CGame::score = 0;
					}
					break;
				case 1:
					if (CGame::iPlayerLives > 0)
					{
						CGame::iPlayerLives--;
					}
					break;
				case 2:
					if (CGame::iAlienSpeedMult > -2)
					{
						CGame::iAlienSpeedMult--;
					}
					break;
				case 3:
					if (CGame::iBulletSpeedMult > -2)
					{
						CGame::iBulletSpeedMult--;
					}
					break;
				default:
					break;
				}

				break;
			case sf::Keyboard::Right:
				switch (iCurrentIndex)
				{
					case 0:
						CGame::score += 10;
						break;
					case 1:
						CGame::iPlayerLives++;
						break;
					case 2:
						if (CGame::iAlienSpeedMult < 5)
						{
							CGame::iAlienSpeedMult++;
						}
						break;
					case 3:
						if (CGame::iBulletSpeedMult < 5)
						{
							CGame::iBulletSpeedMult++;
						}
						break;
					default:
						break;
				}
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
	
	Options[0].setString("> Score: " + std::to_string(CGame::score));
	Options[1].setString("> Lives: " + std::to_string(CGame::iPlayerLives));
	Options[2].setString("> Alien Speed: " + std::to_string(CGame::iAlienSpeedMult));
	Options[3].setString("> Bullet Speed: " + std::to_string(CGame::iBulletSpeedMult));
	Options[0].setFillColor(sf::Color::White);
	Options[1].setFillColor(sf::Color::White);
	Options[2].setFillColor(sf::Color::White);
	Options[3].setFillColor(sf::Color::White);

	Options[iCurrentIndex].setString("$/:" + Options[iCurrentIndex].getString() + "  -/+");
	Options[iCurrentIndex].setFillColor(sf::Color::Green);

	for each (sf::Text text in Options)
	{
		window->draw(text);
	}
	window->draw(instructions);
	window->display();

}



