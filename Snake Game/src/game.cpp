#include"../include/game.h"


void Game::initiateGame()
{
	int choice,status,flag=1;
	userInterface ui;
	ScoreBoard sb;
	
	while(flag)
	{
		choice=ui.displayMainMenu();	
		switch(choice)
		{
			case 1:
				initiateNewGame(sb);
				break;
		
			case 2:
			//	initiateLoadGame(sb,ui);
				break;
				
			case 3:
			//	initiateChangeSettings(sb,ui);
				break;
				
			case 4:	
			//	initiateViewHelp(sb,ui);
				break;
				
			case 5:
				status=ui.askForConfirmation();
				if(status==1)
				{
					ui.clearScreen();
					flag=0;					
				}
				break;
								
			default:
				break;
		}	
	}		
}

int Game::initiateNewGame(ScoreBoard & sb)
{
	userInterface ui;
	int status,flag=1;
	while(flag)
	{
		ui.clearScreen();
		int choice=ui.displayGameLevelMenu();
		switch(choice)
		{
			case 1:
				status=playEasyGame(sb,100);
				break;
			case 2:
				status=playEasyGame(sb,60);
				break;
			case 3:
				status=playEasyGame(sb,30);
				break;
			case 4:
				flag=0;
				break;
		}
	}
}



int Game::playEasyGame( ScoreBoard &sb,int gameLevel)
{
	userInterface ui;
	Food f;
	Snake s;
	do
	{
		ui.clearScreen();
		//ui.displayBoundry();
		ui.displayFood(f);
		int direction=ui.readUserInput(s);
		
		/*if boost active increase speed of game*/
		if(direction==BOOST && gameLevel>=40)
			gameLevel=gameLevel-10;
		else if(direction!=BOOST)
			s.setCurDir(direction);	
		s.moveSnake();
		
				
		int clash=s.checkCollision();			
		if(clash==TRUE)
		{
			ui.displayCollision(s);
			ui.sleep();
			ui.displayGameOver();
			ui.exitGame();
		}
		
		/*Food found*/
		Cell head=s.getHead();
		if(head.getX()==f.getX() && head.getY()==f.getY())
		{		
			s.increaseSnakeSize();
			f.changeFoodLocation();	
			sb.updateScore();
		}
		ui.displaySnake(s);
	
		s.setPreDir(s.getCurDir());
		
		/*vary the delay depending upon player level*/		
		ui.delay(gameLevel);	
	}while(1);
}
