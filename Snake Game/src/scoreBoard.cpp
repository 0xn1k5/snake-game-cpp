#include"../include/scoreBoard.h"

ScoreBoard::ScoreBoard()
{
	player="Rabbit";
	score=0;
}

void ScoreBoard::updateScore()
{
	score=score+10;
}

int ScoreBoard::getScore()
{
	return score;
}
