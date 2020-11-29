#pragma once
//------------------------------ defines section -----------------------------
#define BOARD_PATH "Board.txt"
//---------------------------- include section -------------------------------
#include <fstream>
#include <vector>
#include "Map.h"
//------------------------------ using section -------------------------------
using std::ifstream;
/*----------------------------------------------------------------------------
 * BoardReader
 * The class is loading the Boards file, and return it's information by the
 * needed syntax.
*/
class BoardReader {
public:
	//------------------------- constractors section -------------------------
	BoardReader();

	//------------------------- method section -------------------------------

	bool thereIsNextLevel(); // not const because tellg() isn't const.
	Map readNextLevel();
private:
	//--------------------- privete methods section --------------------------
	
	int receiveMapSize();

	//------------------------ members section -------------------------------

	ifstream m_boardReader;
};
