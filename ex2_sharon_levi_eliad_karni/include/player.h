#ifndef _Player_H
#define _Player_H
#pragma once
//---------------------------- include section -------------------------------
#include "Location.h"
#include "Map.h"

/*----------------------------------------------------------------------------
 * Player
 * The class is a player of the game.
*/
class Player {
public:
	//------------------------- constractors section -------------------------

	Player(Location location = Location(0, 0))
		: m_location(location) {}
	//-------------------------- gets section --------------------------------

	Location getLocation() const;
	//------------------------- method section -------------------------------

	void PlayTurn(const Map &map);
private:
	//------------------------ members section -------------------------------

	Location m_location;
};
#endif // !_Player_H
