#ifndef _Map_H
#define _Map_H
#pragma once
//---------------------------- include section -------------------------------
#include <vector>
#include"Location.h"
//------------------------------ using section -------------------------------
using std::vector;
//------------------------------ defines section -----------------------------

#define NOTHING ' '
#define WALL '#'
#define LADDER 'H'
#define ROD  '-'
#define PLAYER_CLIME 'S'
#define COIN '*'
#define PLAYER '@'
#define ENEMY '%'
/*----------------------------------------------------------------------------
 * Map
 * The Map class is holding the stage's const parameters, the initial dynamyc
 * objects, and movement calc and avalibles methods.
*/
class Map {	
public:
	//------------------------- constractors section -------------------------

	Map(vector<vector<char>> m_stage = {},
		Location m_initialPlayerLoc = Location(),
		vector<Location> m_initialCoinsLoc = {},
		vector<Location> m_initialEnemiesLoc = {});
	//-------------------------- gets section --------------------------------

	Location getLocationAfterFallDown(const Location&)const;
	Location getInitialPlayerLoc()			const;
	vector<Location> getInitalsEnemyLocs()		const;
	vector<Location> getInitalsCoinsLocs()		const;
	vector<vector<char>> getStageMap()		const;
	int getMapSize()				const;
	char getContent(const Location&)		      const;
	//------------------------- method section -------------------------------

	Location isMovePossible         (const Location&, int)const;
	Location upMove                      (const Location&)const;
	Location downMove                    (const Location&)const;
	Location rightMove                   (const Location&)const;
	Location leftMove                    (const Location&)const;
	bool mapException(const Location&)                    const;

private:
	//------------------------ members section -------------------------------

	vector<vector<char>> m_stageMap;
	int m_mapSize;
	Location m_initialPlayerLoc;
	vector<Location> m_initialCoinsLoc;
	vector<Location> m_initialEnemiesLoc;
};
#endif // !_Map_H
