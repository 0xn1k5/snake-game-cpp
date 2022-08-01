#ifndef __SCORE_BOARD__
#define __SCORE_BOARD__
#include "headerList.h"
class ScoreBoard
{
	/*knowing responsibility*/
	string player;
	int score;
	
	/*doing responsibility*/
	public:
		ScoreBoard(void);
		void updateScore(void);	
		int getScore(void);
};
#endif
