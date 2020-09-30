#include "Laser.h"


// ********************************************************************************
/// <summary>
/// <para>
/// Constructor for Class: CLaser
/// </para>
/// </summary>
/// <param name="_fX"><para>
/// 			Type: float, Specifies X coord to spawn the Laser at
/// 		</para></param>
/// <param name="_fY"><para>
/// 			Type: float, Specifies Y coord to spawn the Laser at
/// 		</para></param>
/// <returns></returns>
// ********************************************************************************
CLaser::CLaser(float _fX, float _fY)
{
	fX = _fX;
	fY = _fY;
	laserRect.setSize(sf::Vector2f(8, 40));
	laserRect.setOutlineThickness(2);
	laserRect.setOutlineColor(sf::Color::White);
	laserRect.setFillColor(sf::Color::White);
	laserRect.setOrigin(sf::Vector2f(4, 8));
	laserRect.setPosition(sf::Vector2f(fX, fY));
}

// ********************************************************************************
/// <summary>
/// <para>
/// Destructor for Class: CLaser
/// </para>
/// </summary>
/// <returns></returns>
// ********************************************************************************
CLaser::~CLaser()
{
}

// ********************************************************************************
/// <summary>
/// <para>
/// Function name: FixedUpdate
/// Function is part of Class: CLaser
/// </para>
/// </summary>
// ********************************************************************************
void CLaser::FixedUpdate()
{
	if (bIsEnabled)
	{
		fY += 1;
		laserRect.setPosition(sf::Vector2f(fX, fY));
		CWindowUtilities::Draw(&laserRect);
	}
}
