#ifndef _player_state_H
#define _player_state_H
#pragma once
//------------------------------ defines section -----------------------------
#define NUM_OF_LIFE 3
#define COIN_SCORE 2
#define LEVEL_UP_SCORE 50

/*----------------------------------------------------------------------------
 * PlayerState
 *The class is follow the player state throue the game and updete its:
 *score, life counter and its level.
*/
class PlayerState {
public:
	//------------------------- constractors section -------------------------
	
	PlayerState();
	//-------------------------- gets section --------------------------------
	
	unsigned int getLifeState()const;
	unsigned int getScoreState()const;
	unsigned int getLevelState()const;
	//------------------------- method section -------------------------------
	
	void die();
	void collectCoin();
	void levelup();
private:
	//------------------------ members section -------------------------------

	unsigned int m_life;
	unsigned int m_score;
	unsigned int m_level;
};
#endif // !_player_state_H
