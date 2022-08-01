#ifndef __USERINTERFACE__
#define __USERINTERFACE__
#include "macros.h"
#include "headerList.h"
#include "game.h"
#include "food.h"
#include "snake.h"

#include "globalVariables.h"
class userInterface
{
	public:
	void clearScreen(void);
	void delay(int);
	void wait();
	void gotoxy(int,int);
	int displayMainMenu(void);
	int displayGameLevelMenu(void);
	int askForConfirmation(void);
	void displayLogo(void);
	void displayMessage(string);
	string getFileContents (ifstream&);
	void displayBoundry(void);
	int readUserInput(Snake);
	void displayFood(Food);
	void displaySnake(Snake);	
	void exitGame();
	void displayGameOver();
	void displayDottedLine();
	void displayLine();
	void displayCollision(Snake&);
	void displayColor(char, int);
	void displayColor(string, int);
	void displayArrow(int);
	
	void sleep();
};
#endif
