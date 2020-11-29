/* ex2
 * ===========================================================================
 * Writen by:
 * Sharon Levi | ID: 311593313 | login: sharonlevi
 * Eliad Karni | ID: 206329104 | login: eliadka
 *
 */

 //---------------------------- include section ------------------------------
#include "Controller.h"
//------------------------------ using section -------------------------------
using std::ifstream;
//------------------------------ main section --------------------------------
int main()
{
	//--------------------- parameters declareation --------------------------
	Controller gameContraller = Controller();
	//-------------------------- running games -------------------------------
	gameContraller.runGame();
	//------------------------- program ending -------------------------------
	return (EXIT_SUCCESS);
}
