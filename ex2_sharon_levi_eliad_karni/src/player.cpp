/* Player
 * ===========================================================================
 *
 */
 //---------------------------- include section -------------------------------
#include "Player.h"
#include "Map.h"
#include "Location.h"
#include "Utilities.h"
//------------------------------ gets section --------------------------------
/*----------------------------------------------------------------------------
 * The get get method return the enemy's location on the map.
 * input: none.
 * output: enemy's location on the map.
*/
Location Player::getLocation() const { return this->m_location; }
//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method is playing the player turn by the demanded method.
 * input: level's map.
 * output: none.
*/
void Player::PlayTurn(const Map &map){
	Location newLocation = this->m_location;
	while (this->m_location == newLocation) {
		int key = receiveKey();
		newLocation =
			map.isMovePossible(this->m_location, key);
	}
	if (map.getContent(newLocation) == LADDER)
		moveObject(map, getLocation(), newLocation, PLAYER_CLIME);
	else
		moveObject(map, getLocation(), newLocation, PLAYER);
	this->m_location = newLocation;
}