////////////////////////////////////////////////////////////
//==========================================================
// Bachelor of Software Engineering                       
// Media Design School                                    
// Auckland                                               
// New Zealand                                            
//----------------------------------------------------------
// (c) 2020 Media Design School                           
//==========================================================
//   File Name  : Main.cpp                          
//----------------------------------------------------------
//  Description : Entry point of the program. Contains the    
//  Main Menu code as well as the loading and saving of                                                       
//  Leaderboard data, polling system time, and reading                                                      
//  Windows User Account data to personalise the experience.                                                      
//----------------------------------------------------------
//    Author    : Nerys Thamm BSE20021                    
//----------------------------------------------------------
//    E-mail    : NerysThamm@gmail.com                    
//==========================================================
////////////////////////////////////////////////////////////

#include <SFML/Graphics.hpp>
#include <string>
#include "EasySFML.h"
#include <algorithm>
#include "Game.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <lmcons.h>
#include <ctime>
#include <time.h>
#include <sstream>


namespace ns {
	// --------------------------------------------------------------------------------
	/// <summary>
	/// Struct to store Leaderboard Data
	/// </summary>
	// --------------------------------------------------------------------------------
	struct ScoreData
	{
		/// <summary>Stores the Players Score</summary>
		int score;

		/// <summary>Stores the Players Name</summary>
		std::string player;

		/// <summary>Stores the Date and Time the High Score was made</summary>
		std::string time;
	};
}

int main()
{
	//Get the Player's Windows account username
	char name[UNLEN + 1];
	DWORD name_len = UNLEN + 1;
	GetUserName(name, &name_len);

	//Convert it to a string
	std::string Username = "";
	for (int i = 0; i < name_len-1; i++)
	{
		if (name[i] != ' ')
		{
			Username += name[i];
		}
	}
	
	//Create the Main window
	sf::RenderWindow window(sf::VideoMode(800, 700), "Space Invaders - Nerys Thamm");
	srand(764387493475); //Initialise random
	sf::Event event; //Instantiate event stack

	std::ifstream Reader; //Create file reader
	std::vector<ns::ScoreData> HighScores; //Create HighScore list
	ns::ScoreData data; //create Score Data struct

	//Open the Leaderboard file and read the number of ScoreData stored from the first line
	int len;
	Reader.open("Resources/Leaderboard.dat");
	Reader >> len;

	//Skip to the second line
	Reader.ignore(10, '\n');

	for (int i = 0; i < len; i++) //For every ScoreData in the file
	{
		std::string line;
		std::string temp;

		std::getline(Reader, line); //store the current line in a string
		std::istringstream dataStream(line); //create a stringstream from the string

		//Parse the stream
		std::getline(dataStream, temp, '%');
		data.score = std::stoi(temp);
		std::getline(dataStream, data.player, '%');
		std::getline(dataStream, data.time, '%');
		HighScores.push_back(data);
	}

	Reader.close(); //Close the file

	
	//Create the Main Menu
	int iScore = 0; 
	bool bInMenu = true;
	bool bIsPlaying = false;
	std::string Leaderboard = "Leaderboard:";
	int iTemp = 0;
	for (std::vector<ns::ScoreData>::reverse_iterator i = HighScores.rbegin(); i != HighScores.rend(); ++i) //Create the leaderboard from the list of high scores
	{
		if (iTemp++ < 4)
		{
			Leaderboard += ("\n\n[Score: " + std::to_string(i->score) + "] \n[Player: " + i->player + "] \nTime:\n" + i->time);
		}

	}

	//load a font from resources...
	sf::Font font;
	font.loadFromFile("Resources/sansation.ttf");

	//Instantiate the UI elements
	sf::Text title;
	sf::Text prompt;
	sf::Text lboard;
	sf::Text gameoverTitle;
	sf::Text gameoverPrompt;
	sf::Text gameoverInfo;

	//Config Title
	title.setPosition(10, 10);
	title.setFillColor(sf::Color::White);
	title.setFont(font);
	title.setCharacterSize(100);
	title.setString("Space Invaders");

	//Config Prompt
	prompt.setPosition(275, 175);
	prompt.setFillColor(sf::Color::White);
	prompt.setFont(font);
	prompt.setString("Press [Spacebar] to play, " + Username + "! \n\nControls:\n[A] Move Left\n[D] Move Right\n[S] Shoot\n[Esc] Toggle Debug Menu\n\nCredits:\n[Creator] Nerys Thamm\n[Sprites] classicgaming.cc\n[Special thanks] " + Username + ", for playing!\n[...] See README");

	//Config Leaderboard
	lboard.setPosition(10, 175);
	lboard.setFillColor(sf::Color::White);
	lboard.setFont(font);
	lboard.setCharacterSize(22);
	lboard.setString(Leaderboard);

	//Config Gameover Title
	gameoverTitle.setPosition(30, 20);
	gameoverTitle.setFillColor(sf::Color::White);
	gameoverTitle.setFont(font);
	gameoverTitle.setCharacterSize(140);
	gameoverTitle.setString("Game Over!");

	//Config Gameover Prompt
	gameoverPrompt.setPosition(200, 400);
	gameoverPrompt.setFillColor(sf::Color::White);
	gameoverPrompt.setFont(font);
	gameoverPrompt.setString("Press [Spacebar] to continue...");

	//Config Gameover Info
	gameoverInfo.setPosition(80, 200);
	gameoverInfo.setFillColor(sf::Color::White);
	gameoverInfo.setFont(font);
	gameoverInfo.setString("");

	//Instantiate the Game
	CGame game;
	
	
	while (window.isOpen()) //While the window is open...
	{
			while (window.pollEvent(event)) // for every event in the event stack...
			{
				switch (event.type)
				{
				case sf::Event::Closed: //If the window is being closed, close the window
					window.close();
					break;
				case sf::Event::KeyPressed: //If a key has been pressed...
					switch (event.key.code)
					{
					case sf::Keyboard::Space: //If that key was Space...
						if (bInMenu) //And the player is currently in the main menu
						{
							iScore = game.Start(); //Start the game window and retrieve the players score when the game ends
							bInMenu = false;

							//Get and format date and time
							time_t now = time(0);
							tm ftime;
							localtime_s(&ftime, &now);
							char buffer[50];
							strftime(buffer, 50, "[%d/%m/%y][%T]", &ftime);

							if (HighScores.empty()) //If there are no High Scores...
							{
								HighScores.push_back(ns::ScoreData{ iScore, Username, buffer }); //Add a new high score using the players score, their username, and the formatted date and time
							}
							else if (iScore > HighScores.back().score) //Or the players score is higher than the highest top score...
							{
								HighScores.push_back(ns::ScoreData{ iScore, Username, buffer }); //Add a new high score using the players score, their username, and the formatted date and time
							}

							//Update the leaderboard with the new data
							Leaderboard = "Leaderboard:";
							int iTemp = 0;
							for (std::vector<ns::ScoreData>::reverse_iterator i = HighScores.rbegin(); i != HighScores.rend(); ++i)
							{
								if (iTemp++ < 4)
								{
									Leaderboard += ("\n\n[Score: " + std::to_string(i->score) + "] \n[Player: " + i->player + "] \nTime:\n" + i->time);
								}

							}
							lboard.setString(Leaderboard);

							//Prepare the gameover UI based on player score
							gameoverInfo.setString("You scored " + std::to_string(iScore) + ((iScore < 400) ? " points? Thats embarrassing, " : " points? Not bad at all, ") + Username + "!");
						}
						else
						{
							bInMenu = true;
						}
						break;
					default:
						break;
					}
				default:
					break;
				}
				
			}
			
			window.clear(); //Clear the window
			
			if (bInMenu) //If the player is in the menu...
			{
				window.draw(title); //Draw the main menu UI
				window.draw(prompt);
				window.draw(lboard);
			}
			else //Otherwise...
			{
				window.draw(gameoverTitle); //Draw the game over UI
				window.draw(gameoverPrompt);
				window.draw(gameoverInfo);
			}

			window.display(); //Display the drawn frame to the window
			
	}
	
	
	//WHEN THE WINDOW HAS BEEN CLOSED

	std::ofstream Writer("Resources/Leaderboard.dat"); //Create a file writer and open the leaderboard file
	Writer << HighScores.size() << std::endl; //Update the size specifier in the file
	for each (ns::ScoreData score in HighScores) //format every high score and write it to the file
	{
		Writer << std::to_string(score.score) + "%" + score.player + "%" + score.time + "%" << std::endl;
	}
	Writer.close(); //Close the file
	
	
	return 0; //Close the Program
}