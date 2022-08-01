#include"../include/food.h"
int Food::getX()
{
	return x;
}
int Food::getY()
{
	return y;
}
char Food::getSymbol()
{
	return symbol;
}
void Food::changeFoodLocation()
{
	x=randomise(RIGHT_MARGIN -1);
	y=randomise(BOTTOM_MARGIN -1);
}

int Food::randomise(int max)
{
	int num=0;
	srand( (unsigned)time(NULL) );
	do
	{	
		num=rand() % max;
	}while(num==0);
	return num;	
}

Food::Food()
{
	changeFoodLocation();
	symbol=FOOD_ICON;
}

