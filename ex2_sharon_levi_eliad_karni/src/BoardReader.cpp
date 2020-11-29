/* BoardReader
 * ===========================================================================
 */
 //---------------------------- include section -------------------------------
#include "BoardReader.h"
#include <fstream>
#include "Utilities.h"
#include "Map.h"

//-------------------------- constractors section ----------------------------
/*----------------------------------------------------------------------------
 * The constractor is open the levels file and then the file reader
 * is waiting to load the first stage.
 * input: none.
 * output: none.
*/
BoardReader::BoardReader() {
	this->m_boardReader.open(BOARD_PATH);
	if (!(this->m_boardReader.is_open()))
		terminate("opening boards files error!");
}
//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method check if there is a new level to load.
 * input: None.
 * output: true if there is new level and false if isn't.
*/
bool BoardReader::thereIsNextLevel() {
	return (this->m_boardReader.peek() == '\n');
}
/*----------------------------------------------------------------------------
 * The method read a new level from the file into a 2D vector.
 * input: None.
 * output: the new level as a map object.
*/
Map BoardReader::readNextLevel() {
	vector<vector<char>> map;
	bool playerReceived = false;
	char receivedChar;
	int size = receiveMapSize();

	Location playerLoc;
	vector<Location> enemysLocs;
	vector<Location> coinsLocs;

	if(this->m_boardReader.peek() == '\n')
		this->m_boardReader.get();
	for (int i = 0; i < size; ++i) {
		vector<char> receivedMapRow = {};
		for (int j = 0; j < size; ++j) {
			this->m_boardReader.get(receivedChar);
			switch (receivedChar)
			{
			case PLAYER:
				if (playerReceived)
					terminate("player received twice!");
				playerReceived = true;
				playerLoc = Location(i, j);
				receivedMapRow.push_back(NOTHING);
				break;
			case PLAYER_CLIME:
				if (playerReceived)
					terminate("player received twice!");
				playerReceived = true;
				playerLoc = Location(i, j);
				receivedMapRow.push_back(LADDER);
				break;
			case ENEMY:
				enemysLocs.push_back(Location(i, j));
				receivedMapRow.push_back(NOTHING);
				break;
			case WALL:
				receivedMapRow.push_back(WALL);
				break;
			case NOTHING:
				receivedMapRow.push_back(NOTHING);
				break;
			case LADDER:
				receivedMapRow.push_back(LADDER);
				break;
			case ROD:
				receivedMapRow.push_back(ROD);
				break;
			case COIN:
				coinsLocs.push_back(Location(i, j));
				receivedMapRow.push_back(NOTHING);
				break;
			default:
				std::string errorMessage = "receiving the char ";
				errorMessage.append(1, receivedChar);
				errorMessage.append(" not declered!");
				terminate(errorMessage);
				break;
			}
		}
		if(this->m_boardReader.peek() != '\0')
			this->m_boardReader.get();
		map.push_back(receivedMapRow);
	}
	if (!playerReceived)
		terminate("player location where not received!");
	return Map(map, playerLoc, coinsLocs, enemysLocs);
}
/*----------------------------------------------------------------------------
 * The method check if the input size are a digits and what is the
 * size of the received map.
 * input: None
 * output: the size of the received map as an integer number.
*/
int BoardReader::receiveMapSize() {
	unsigned int size = 0;
	std::string charSize;
	this->m_boardReader >> charSize;
	for (int i = 0; i < charSize.size(); ++i) {
		if (!isdigit(charSize[i]))
			terminate("size receiving error!");
		size *= 10;
		size += charSize[i] - '0';
	}
	this->m_boardReader.get();//get /n
	return size;
}
