#include"../include/cell.h"

int Cell::getX()
{
/*	if(x==LEFT_MARGIN)
		x=RIGHT_MARGIN;
	else if(x==RIGHT_MARGIN)
		x=LEFT_MARGIN;	
		*/	
	
	return x;
}

int Cell::getY()
{
/*	if(y==TOP_MARGIN)
		y=BOTTOM_MARGIN;
	else if(y==BOTTOM_MARGIN)
		y=TOP_MARGIN;*/
			
	return y;
}

char Cell::getSymbol()
{
	return symbol;
}

void Cell::setX(int x)
{
	if(x==LEFT_MARGIN)
		this->x=RIGHT_MARGIN-BORDER;
	else if(x==RIGHT_MARGIN)
		this->x=LEFT_MARGIN+BORDER;
	else
		this->x=x;
}

void Cell::setY(int y)
{
	if(y==TOP_MARGIN)
		this->y=BOTTOM_MARGIN-BORDER;
	else if(y==BOTTOM_MARGIN)
		this->y=TOP_MARGIN+BORDER;
	else	
		this->y=y;
}

void Cell::setSymbol(char symbol)
{
	this->symbol=symbol;
}

Cell::Cell()
{
	symbol=SNAKE_BODY_ICON;
}

Cell::Cell(int x, int y)
{
	this->x=x;
	this->y=y;
	symbol=SNAKE_BODY_ICON;
}

Cell::Cell(int x, int y, char sym)
{
	this->x=x;
	this->y=y;
	symbol=sym;
}
