#ifndef _Enemy_H
#define _Enemy_H
#pragma once
//---------------------------- include section -------------------------------
#include "Location.h"
#include "Map.h"

/*----------------------------------------------------------------------------
 * Enemy
 * The class is an a enemy at the game.
*/
class Enemy {
public:
	//------------------------- constractors section -------------------------

	Enemy(const Location &location = Location(0, 0));
	//-------------------------- gets section --------------------------------

	Location getLocation()const;
	//------------------------- method section -------------------------------

	void playTurn(const Map& map, const Location& playerLocation);
private:
	//------------------------ members section -------------------------------

	Location m_location;
};
#endif // !_Enemy_H
