////////////////////////////////////////////////////////////
//==========================================================
// Bachelor of Software Engineering                       
// Media Design School                                    
// Auckland                                               
// New Zealand                                            
//----------------------------------------------------------
// (c) 2020 Media Design School                           
//==========================================================
//   File Name  : Bullet.cpp                          
//----------------------------------------------------------
//  Description : Contains the implementation for the     
//  CBullet class.                                                      
//                                                        
//                                                        
//----------------------------------------------------------
//    Author    : Nerys Thamm BSE20021                    
//----------------------------------------------------------
//    E-mail    : NerysThamm@gmail.com                    
//==========================================================
////////////////////////////////////////////////////////////
#include "Bullet.h"
#include "Game.h"

CBullet::CBullet(float _fX)
{
	fX = _fX; //Set Coords
	fY = 950;

	//Config bullet shape
	bulletRect.setSize(sf::Vector2f(1, 16));
	bulletRect.setOutlineThickness(2);
	bulletRect.setOutlineColor(sf::Color::White);
	bulletRect.setFillColor(sf::Color::White);
	bulletRect.setOrigin(sf::Vector2f(1, 2));
	bulletRect.setPosition(sf::Vector2f(fX, fY));
}

void CBullet::Update(float _fDeltaTime)
{
	fY -= 400 * _fDeltaTime * CGame::iBulletSpeedMult; //move the bullet upwards by an amount determined by DeltaTime
	bulletRect.setPosition(sf::Vector2f(fX, fY)); //Update the bullets position
	CWindowUtilities::Draw(&bulletRect); //Prepare the bullet to be drawn
}


