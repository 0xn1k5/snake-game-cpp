#ifndef __FOOD__
#define __FOOD__
#include"macros.h"
#include"headerList.h"
class Food
{
	/*knowning responsibility*/
	int x,y;
	char symbol;
	
	/*doing responsibility*/
	public:
	int getX();
	int getY();
	char getSymbol();
	void changeFoodLocation();
	int randomise(int);
	Food();
};
#endif
