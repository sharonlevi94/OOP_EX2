/* Player_state
 * ===========================================================================
 *
 */
//---------------------------- include section -------------------------------
#include "Player_state.h"
//-------------------------- constractors section ----------------------------
/*----------------------------------------------------------------------------
 * The constractor is define the PlayerState arguments to bo 0's.
 * input: none.
 * output: none.
*/
PlayerState::PlayerState() 
	: m_life(NUM_OF_LIFE), m_score(0) , m_level(0) {}
//------------------------------ gets section --------------------------------
/*----------------------------------------------------------------------------
 * The get method return the PlayerState's life state.
 * input: none.
 * output: players life state.
*/
unsigned int PlayerState::getLifeState() const { return(this->m_life);}
/*----------------------------------------------------------------------------
 * The get method returns the PlayerState score state.
 * input: none.
 * output: players score.
*/
unsigned int PlayerState::getScoreState() const { return(this->m_score);}
/*----------------------------------------------------------------------------
 * The get method returns the PlayerState level state.
 * input: none.
 * output: players score.
*/
unsigned int PlayerState::getLevelState()const { return(this->m_level); };
//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method is decrease the player life amount by 1.
 * input: none.
 * output: none.
*/
void PlayerState::die() {
	if (this->m_life > 0)
		--this->m_life;
}
/*----------------------------------------------------------------------------
 * The method is updating the player's score in coin colecing occation by the
 * demanded roles.
 * input: none.
 * output: none.
*/
void PlayerState::collectCoin() {
	this->m_score += this->m_level * COIN_SCORE;
}
/*----------------------------------------------------------------------------
 * The method is updating the player score in level up occation by the 
 * demanded roles and update the level argument.
 * input: none.
 * output: none.
*/
void PlayerState::levelup() {
	this->m_score += this->m_level * LEVEL_UP_SCORE;
	++(this->m_level);
}