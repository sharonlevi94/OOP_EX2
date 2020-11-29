/* Enemy
 * ===========================================================================
 *
 */
//---------------------------- include section -------------------------------
#include "Enemy.h"
#include "Map.h"
#include "Location.h"
#include "Utilities.h"

//-------------------------- constractors section ----------------------------
/*----------------------------------------------------------------------------
 * The constractor is defining Enemys location by the received location.
 * The constractor is the default constractor.
 * input: Enemye's wanted location.
 * output: none.
*/
Enemy::Enemy(const Location& location) : m_location(location) {}
//------------------------------ gets section --------------------------------
/*----------------------------------------------------------------------------
 * The get method return the enemy's location on the map.
 * input: none.
 * output: enemy's location on the map.
*/
Location Enemy::getLocation()const { return this->m_location; }
//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method calculate the enemyes move and update it on the screen.
 * input: the stage map and the player's location.
 * output: none.
*/
void Enemy::playTurn(const Map& map, const Location& playerLocation) {
	Location moveAns = this->m_location;
	if (getLocation().col != playerLocation.col) {
		if (isRightOf(playerLocation, getLocation()))
			moveAns = map.rightMove(getLocation());
		else if (isLeftOf(playerLocation, getLocation()))
			moveAns = map.leftMove(getLocation());
	}
	if (moveAns == getLocation()) {
		if (isAboveOf(playerLocation, getLocation()))
			moveAns = map.upMove(getLocation());
		else
			moveAns = map.downMove(getLocation());
	}
	moveObject(map, getLocation(), moveAns, ENEMY);
	this->m_location = moveAns;
}