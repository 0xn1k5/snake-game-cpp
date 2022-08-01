#include"../include/snake.h"

vector<Cell> Snake::getSnakeBody()
{
	return snakeBody;
}

void Snake::increaseSnakeSize()
{
	int x=snakeBody[snakeBody.size()-1].getX();
	int y=snakeBody[snakeBody.size()-1].getY();
	if(previousDirection==UP)
		y++;
	else if(previousDirection==DOWN)
		y--;
	else if(previousDirection==LEFT)
		x++;
	else if (previousDirection==RIGHT)
		x--;	
	
	Cell lastCell(x,y);
	snakeBody.push_back(lastCell);
}

int Snake::getPreDir()
{
	return previousDirection;
}

int Snake::getCurDir()
{
	return currentDirection;
}

void Snake::setPreDir(int previousDirection)
{
	this->previousDirection=previousDirection;
}

void Snake::setCurDir(int currentDirection)
{
	this->currentDirection=currentDirection;
}

Cell Snake::getHead()
{
	return snakeBody[0];
}

int Snake::getSize()
{
	return snakeBody.size();
}

void Snake::moveSnake()
{
	/*move the snake body according to his head*/
	for(int i=snakeBody.size()-1; i>0;i--)
	{
		snakeBody[i].setX(snakeBody[i-1].getX());
		snakeBody[i].setY(snakeBody[i-1].getY());
	}

	/*change direction of snake's head*/
	if(currentDirection==UP)
	{
		snakeBody[0].setY(snakeBody[0].getY()-1);	
	}
	else if(currentDirection==DOWN)
	{
		snakeBody[0].setY(snakeBody[0].getY()+1);
	}
	else if(currentDirection==LEFT)
	{
		snakeBody[0].setX(snakeBody[0].getX()-1);
	}
	else if(currentDirection==RIGHT)
	{
		snakeBody[0].setX(snakeBody[0].getX()+1);
	}
}

int Snake::checkCollision()
{
	int headX=snakeBody[0].getX();
	int headY=snakeBody[0].getY();
	for(int i=1;i<snakeBody.size();i++)
	{
		if(headX==snakeBody[i].getX() && headY==snakeBody[i].getY())
			return TRUE;
	}
	
}

void Snake::updateHeadSymbol(char headIcon)
{
	snakeBody[0].setSymbol(headIcon);
}

Snake::Snake()
{
	Cell firstCell(STARTX,STARTY);
	Cell c2(STARTX,STARTY+1);
	Cell c3(STARTX,STARTY+2);
	Cell c4(STARTX,STARTY+3);
	Cell c5(STARTX,STARTY+4);
	Cell c6(STARTX,STARTY+5);
	Cell c7(STARTX,STARTY+6);
	Cell c8(STARTX,STARTY+7);
	snakeBody.push_back(firstCell);
	snakeBody.push_back(c2);
	snakeBody.push_back(c3);
	snakeBody.push_back(c4);
	snakeBody.push_back(c5);
	snakeBody.push_back(c6);
	snakeBody.push_back(c7);
	snakeBody.push_back(c8);
	previousDirection=UP;
	currentDirection=UP;	
}
