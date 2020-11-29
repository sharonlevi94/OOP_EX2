//---------------------------- include section -------------------------------
#include "Map.h"
#include "Location.h"
#include "io.h"
#include <vector>

//========================================================================
/*
* Constructor of the map:
* Get from the BoardReader all the initials locations and set this data
* in the members of the class.
*/
Map::Map(vector<vector<char>> stage, Location initialPlayerLoc,
	vector<Location> initialCoinsLoc, 
	 vector<Location> initialEnemiesLoc) :
	m_stageMap(stage), m_mapSize((int)stage.size()),
	m_initialPlayerLoc(initialPlayerLoc), 
        m_initialCoinsLoc(initialCoinsLoc),
	m_initialEnemiesLoc(initialEnemiesLoc) {}

//========================================================================
//===================Get_Functions========================================
//return the wanted member of the class Map
vector<vector<char>> Map::getStageMap()const 
{ return m_stageMap; }
int    Map::getMapSize()const 
{ return m_mapSize;  }
Location Map::getInitialPlayerLoc()const 
{ return this->m_initialPlayerLoc; }
vector<Location> Map::getInitalsCoinsLocs()const
{ return this->m_initialCoinsLoc; }
vector<Location> Map::getInitalsEnemyLocs() const 
{ return this->m_initialEnemiesLoc; }
//========================================================================
/*
* Input: Location of some object and keyboard value(UP/DOWN/LEFT/RIGHT)
* Output: Move is Possible-> New Location after the move.
*         Move isn't Possible-> The original Location.
*/
Location Map::isMovePossible(const Location& Objloc, int WantedMove )
const{
	switch (WantedMove) {
	case KB_UP: 
		return upMove(Objloc);
		
	case KB_DOWN:
		return downMove(Objloc);

	case KB_LEFT:
		return leftMove(Objloc);

	case KB_RIGHT:
		return rightMove(Objloc);
	}
	return Objloc;
}
//========================================================================
/*
* Input: Location of some object and UP keyboard value
* Output: Move is Possible-> New Location after the move.
*         Move isn't Possible-> The original Location.
*/
Location Map::upMove(const Location& ObjLoc) const{
	if (mapException(Location(ObjLoc.row - 1, ObjLoc.col)) && 
		getContent(Location(ObjLoc.row, ObjLoc.col)) == LADDER)
			return Location(ObjLoc.row - 1, ObjLoc.col);

	return ObjLoc; //player can move up only on the ladder
}
//========================================================================
/*
* Input: Location of some object and Down keyboard value
* Output: Move is Possible-> New Location after the move.
*         Move isn't Possible-> The original Location.
*/
Location Map::downMove(const Location& objLoc) const{
	if (!mapException(Location(objLoc.row + 1, objLoc.col)))
		return objLoc;

	if (getContent(Location(objLoc.row + 1, objLoc.col)) == NOTHING)
		return getLocationAfterFallDown
		(Location(objLoc.row + 1, objLoc.col));
	if (getContent(Location(objLoc.row + 1, objLoc.col)) == LADDER)
		return Location(objLoc.row + 1, objLoc.col);

	return objLoc;
}
//========================================================================
/*
* Input: Location of some object and Right keyboard value
* Output: Move is Possible-> New Location after the move.
*         Move isn't Possible-> The original Location.
*/
Location Map::rightMove(const Location& objLoc) const{
	if (!mapException(Location(objLoc.row, objLoc.col + 1))) 
		//player can't move to the wall
		return objLoc;
	if (getContent(Location(objLoc.row, objLoc.col + 1)) == ROD||
		getContent(Location(objLoc.row, objLoc.col + 1)) == LADDER ||
		!mapException(Location(objLoc.row + 1, objLoc.col + 1)))
		return(Location(objLoc.row, objLoc.col + 1));

	else if(getContent(Location(objLoc.row + 1, objLoc.col + 1)) != WALL &&
		getContent(Location(objLoc.row + 1, objLoc.col + 1)) != LADDER)
		return getLocationAfterFallDown
		(Location(objLoc.row + 1, objLoc.col + 1));

	return Location(objLoc.row, objLoc.col + 1); //can move right
}
//========================================================================
/*
* Input: Location of some object and Left keyboard value
* Output: Move is Possible-> New Location after the move.
*         Move isn't Possible-> The original Location.
*/
Location Map::leftMove(const Location& objLoc) const{
	if (!mapException(Location(objLoc.row, objLoc.col - 1))) 
		//player can't move to the wall
		return objLoc;
	if (getContent(Location(objLoc.row, objLoc.col - 1)) == ROD ||
		getContent(Location(objLoc.row, objLoc.col - 1)) == LADDER ||
		!mapException(Location(objLoc.row + 1, objLoc.col - 1)))
		return(Location(objLoc.row, objLoc.col - 1));

	else if (getContent(Location(objLoc.row + 1, objLoc.col - 1)) != WALL &&
		getContent(Location(objLoc.row + 1, objLoc.col - 1)) != LADDER)
		return getLocationAfterFallDown
		(Location(objLoc.row + 1, objLoc.col - 1));

	return Location(objLoc.row, objLoc.col - 1); //can move left
}
//========================================================================
/*
* Input: Location of some object.
* Output: The right location in the map after falldown of the object
*/
Location Map::getLocationAfterFallDown(const Location& objloc) const{
	int row = objloc.row;
	while (mapException(Location(row, objloc.col))) {
		if (getContent(Location(row, objloc.col)) == ROD)
			break;
		if (!mapException(Location(1 + row, objloc.col))||
			getContent(Location(1 + row, objloc.col)) == LADDER ||
			getContent(Location(1 + row, objloc.col)) == WALL) {
			break;
		}
		row++;
	}
	return Location(row,objloc.col);
}
//========================================================================
/*
* Input: some location in the map
* Output: the content in this location in the map.
*/
char Map::getContent(const Location& loc) const
{
	return m_stageMap[loc.row][loc.col];
}
//========================================================================
/*
* Input: wanted location the object want to move.
* Output: True- if there is an  map exception
          False- if there is not an exception.
*/
bool Map::mapException(const Location& loc) const{
	if (!inRectangle(Location(0, 0), 
	Location(this->m_mapSize, this->m_mapSize), loc))
		return false;
	if(m_stageMap[loc.row][loc.col] == WALL)
		return false;

	return true;
}
