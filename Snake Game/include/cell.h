#ifndef __CELL__
#define __CELL__
#include "macros.h"
class Cell
{
	/*knowing Responsibility*/
	int x,y;
	char symbol;
	
	/*doing resonsibility*/
	public:
	
	int getX();
	int getY();
	char getSymbol();
	void setX(int );
	void setY(int );
	void setSymbol(char);
	Cell();
	Cell(int,int);	
	Cell(int , int , char);
};
#endif
