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
	struct ScoreData
	{
		int score;
		std::string player;
		std::string time;
	};
}

int main()
{
	char name[UNLEN + 1];
	DWORD name_len = UNLEN + 1;
	GetUserName(name, &name_len);
	std::string Username = "";
	for (int i = 0; i < name_len-1; i++)
	{
		if (name[i] != ' ')
		{
			Username += name[i];
		}
	}
	
	sf::RenderWindow window(sf::VideoMode(800, 700), "Space Invaders - Nerys Thamm");
	srand(764387493475);
	sf::Event event;
	std::ifstream Reader;
	std::vector<ns::ScoreData> HighScores;
	ns::ScoreData data;
	int len;
	Reader.open("Resources/Leaderboard.dat");
	Reader >> len;
	Reader.ignore(10, '\n');
	for (int i = 0; i < len; i++)
	{
		std::string line;
		std::string temp;
		std::getline(Reader, line);
		std::istringstream dataStream(line);
		std::getline(dataStream, temp, '%');
		data.score = std::stoi(temp);
		std::getline(dataStream, data.player, '%');
		std::getline(dataStream, data.time, '%');
		HighScores.push_back(data);
	}

	Reader.close();

	
	
	int iScore = 0;
	bool bInMenu = true;
	bool bIsPlaying = false;
	std::string Leaderboard = "Leaderboard:";
	int iTemp = 0;
	for (std::vector<ns::ScoreData>::reverse_iterator i = HighScores.rbegin(); i != HighScores.rend(); ++i)
	{
		if (iTemp++ < 4)
		{
			Leaderboard += ("\n\n[Score: " + std::to_string(i->score) + "] \n[Player: " + i->player + "] \nTime:\n" + i->time);
		}

	}
	sf::Font font;
	font.loadFromFile("Resources/sansation.ttf");
	sf::Text title;
	sf::Text prompt;
	sf::Text lboard;
	sf::Text gameoverTitle;
	sf::Text gameoverPrompt;
	sf::Text gameoverInfo;

	title.setPosition(10, 10);
	title.setFillColor(sf::Color::White);
	title.setFont(font);
	title.setCharacterSize(100);
	title.setString("Space Invaders");

	prompt.setPosition(275, 175);
	prompt.setFillColor(sf::Color::White);
	prompt.setFont(font);
	prompt.setString("Press [Spacebar] to play, " + Username + "! \n\nControls:\n[A] Move Left\n[D] Move Right\n[S] Shoot\n[Esc] Toggle Debug Menu\n\nCredits:\n[Creator] Nerys Thamm\n[Sprites] classicgaming.cc\n[Special thanks] " + Username + ", for playing!\n[...] See README");

	lboard.setPosition(10, 175);
	lboard.setFillColor(sf::Color::White);
	lboard.setFont(font);
	lboard.setCharacterSize(22);
	lboard.setString(Leaderboard);

	gameoverTitle.setPosition(30, 20);
	gameoverTitle.setFillColor(sf::Color::White);
	gameoverTitle.setFont(font);
	gameoverTitle.setCharacterSize(140);
	gameoverTitle.setString("Game Over!");

	gameoverPrompt.setPosition(200, 400);
	gameoverPrompt.setFillColor(sf::Color::White);
	gameoverPrompt.setFont(font);
	gameoverPrompt.setString("Press [Spacebar] to continue...");

	gameoverInfo.setPosition(80, 200);
	gameoverInfo.setFillColor(sf::Color::White);
	gameoverInfo.setFont(font);
	gameoverInfo.setString("");

	CGame game;
	
	
	while (window.isOpen())
	{

		
		
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					switch (event.key.code)
					{
					case sf::Keyboard::Space:
						if (bInMenu)
						{
							iScore = game.Start();
							bInMenu = false;
							time_t now = time(0);
							tm ftime;
							localtime_s(&ftime, &now);
							char buffer[50];
							strftime(buffer, 50, "[%d/%m/%y][%T]", &ftime);
							if (HighScores.empty())
							{
								HighScores.push_back(ns::ScoreData{ iScore, Username, buffer });
							}
							else if (iScore > HighScores.back().score)
							{
								HighScores.push_back(ns::ScoreData{ iScore, Username, buffer });
							}
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
			
			window.clear();
			
			if (bInMenu)
			{
				window.draw(title);
				window.draw(prompt);
				window.draw(lboard);
			}
			else
			{
				window.draw(gameoverTitle);
				window.draw(gameoverPrompt);
				window.draw(gameoverInfo);
			}

			window.display();
			


		


		
	}
	
	
	std::ofstream Writer("Resources/Leaderboard.dat");
	Writer << HighScores.size() << std::endl;
	for each (ns::ScoreData score in HighScores)
	{
		Writer << std::to_string(score.score) + "%" + score.player + "%" + score.time + "%" << std::endl;
	}
	Writer.close();
	
	
	return 0;
}