////////////////////////////////////////////////////////////
//==========================================================
// Bachelor of Software Engineering                       
// Media Design School                                    
// Auckland                                               
// New Zealand                                            
//----------------------------------------------------------
// (c) 2020 Media Design School                           
//==========================================================
//   File Name  : DebugWindow.cpp                          
//----------------------------------------------------------
//  Description : Contains the implementation for the     
//  DebugWindow class.                                                      
//                                                        
//                                                        
//----------------------------------------------------------
//    Author    : Nerys Thamm BSE20021                    
//----------------------------------------------------------
//    E-mail    : NerysThamm@gmail.com                    
//==========================================================
////////////////////////////////////////////////////////////
#include "DebugWindow.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "EasySFML.h"
#include <algorithm>

DebugWindow::DebugWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(400, 400), "Space Invaders - Debug"); //Create the Debug Window
	
	//Config the Text
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
	window->close();//Close and delete the window to free up the memory
	delete window;
}

void DebugWindow::Update(float _fDeltaTime)
{
	while (window->pollEvent(wEvent))//for each event
	{
		switch (wEvent.type) //If the event is...
		{
		case sf::Event::Closed://The window being closed, then close the window
			window->close();
			
			break;
		case sf::Event::KeyPressed://A key being pressed, then...
			switch (wEvent.key.code)
			{
			case sf::Keyboard::Escape: //If the key is escape..
				CGame::bDebugMode = false; //turn debug mode off
				break;
			case sf::Keyboard::Up: //If the key is Up..
				//Cycle upwards through the options
				if (iCurrentIndex > 0)
				{
					iCurrentIndex--;
				}
				else
				{
					iCurrentIndex = 3;
				}
				break;
			case sf::Keyboard::Down: //If the key is Down
				//Cycle downwards through the options
				if (iCurrentIndex < 3)
				{
					iCurrentIndex++;
				}
				else
				{
					iCurrentIndex = 0;
				}

				break;
			case sf::Keyboard::Left: //If the key is Left...
				switch (iCurrentIndex)
				{
				case 0: //and Score is selected..
					if (CGame::score >= 10) //Decrease score by 10 to a minimum of 0
					{
						CGame::score -= 10;
					}
					else
					{
						CGame::score = 0;
					}
					break;
				case 1: //and Lives are selected..
					if (CGame::iPlayerLives > 0) //Decrease lives by 1 to a minimum of 0
					{
						CGame::iPlayerLives--;
					}
					break;
				case 2: //and Alien Speed Multiplier is selected..
					if (CGame::iAlienSpeedMult > -2) //Decrease Alien speed multiplier by 1 to a minimum of -2
					{
						CGame::iAlienSpeedMult--;
					}
					break;
				case 3: //and Bullet speed multiplier is selected..
					if (CGame::iBulletSpeedMult > -2) //Decrease bullet speed multiplier by 1 to a minimum of -2
					{
						CGame::iBulletSpeedMult--;
					}
					break;
				default:
					break;
				}

				break;
			case sf::Keyboard::Right: //If the key is Right...
				switch (iCurrentIndex)
				{
					case 0: //And score is selected..
						CGame::score += 10; //Increase score by 10
						break;
					case 1: //And Lives are selected..
						CGame::iPlayerLives++; //Increase lives by 1
						break;
					case 2: //And Alien speed multiplier is selected..
						if (CGame::iAlienSpeedMult < 5) //Increase alien speed multiplier by 1 to a maximum of 5
						{
							CGame::iAlienSpeedMult++;
						}
						break;
					case 3: //And Bullet speed multiplier is selected..
						if (CGame::iBulletSpeedMult < 5) //Increaase bullet speed multiplier by 1 to a maximum of 5
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
	window->clear(); //Clear the debug window
	
	//Update the Text 
	Options[0].setString("> Score: " + std::to_string(CGame::score));
	Options[1].setString("> Lives: " + std::to_string(CGame::iPlayerLives));
	Options[2].setString("> Alien Speed: " + std::to_string(CGame::iAlienSpeedMult));
	Options[3].setString("> Bullet Speed: " + std::to_string(CGame::iBulletSpeedMult));
	Options[0].setFillColor(sf::Color::White);
	Options[1].setFillColor(sf::Color::White);
	Options[2].setFillColor(sf::Color::White);
	Options[3].setFillColor(sf::Color::White);

	//Give the selected option a green colouring and selection marker
	Options[iCurrentIndex].setString("$/:" + Options[iCurrentIndex].getString() + "  -/+");
	Options[iCurrentIndex].setFillColor(sf::Color::Green);

	for each (sf::Text text in Options) //Draw all the text
	{
		window->draw(text);
	}
	window->draw(instructions);
	window->display(); //Display the frame

}



