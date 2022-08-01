#ifndef __SNAKE__
#define __SNAKE__
#include "cell.h"
#include "headerList.h"
class Snake
{
	/*knowning responsibility*/
	vector<Cell> snakeBody;
	int previousDirection;
	int currentDirection;
	
	/*doing responsibility*/
	public:
	vector<Cell> getSnakeBody(void);
	void increaseSnakeSize(void);
	int checkCollision(void);
	int getPreDir(void);
	int getCurDir(void);
	void setPreDir(int);
	void setCurDir(int);
	void moveSnake();
	Cell getHead(void);
	int getSize(void);
	void updateHeadSymbol(char);
	Snake();
	
};
#endif
