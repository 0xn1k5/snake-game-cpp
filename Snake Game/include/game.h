#ifndef __GAME__
#define __GAME__
#include "userInterface.h"
#include "food.h"
#include "snake.h"
#include "scoreBoard.h"
class Game
{
	/*doing responsibility*/
	public:
	void initiateGame();	
	int initiateNewGame(ScoreBoard &);
	int playEasyGame(ScoreBoard &, int);
};
#endif
