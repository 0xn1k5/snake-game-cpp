#include"../include/userInterface.h"

void userInterface::clearScreen(void)
{
	system("cls");
	
/*	HANDLE hOut;
    COORD Position;
    DWORD Written;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 2;
    Position.Y = 2;
    FillConsoleOutputCharacter(hOut,' ', 1000000, Position, &Written);

    SetConsoleCursorPosition(hOut, Position); */
}

/*
COLOUR CODES
0 = black, 1= deep blue, 2= green 4=wine red, 5= purple, 14=yellow 
13=pink,  12= red, 11= skyblue, 10, green, 15 = white, 
*/

void userInterface::displayColor(char msg, int color)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	std::cout<<msg;
	SetConsoleTextAttribute(hConsole, 15);
}

void userInterface::delay(int duration)
{
	Sleep(duration);
}

void userInterface::gotoxy(int x, int y) 
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void userInterface::wait()
{
	getch();
}

void userInterface::displayMessage(string msg)
{
	cout<<"\t\t\t\t\t\t"<<msg<<endl;
}

void userInterface::displayColor(string msg, int color)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	std::cout<<msg<<endl;
	SetConsoleTextAttribute(hConsole, 15);
}

void userInterface::displayArrow(int enable)
{
	if(enable==1)
		displayColor("\t\t     ", 2);
	else
		cout<<"\t\t     ";
}


void displayMenuItem(string msg)
{
	cout<<msg<<endl;
}

int userInterface::displayMainMenu()
{	
	int flag=1,count=1;
	char input;
	string menu[MENU_SIZE]={"New Game","Load Game","Settings","Help","Quit"};
	while(flag)
	{
		clearScreen();
		cout<<endl;
		displayLogo();
		cout<<endl;
		for(int i=1;i<=MENU_SIZE;i++)
		{
			cout<<"\t\t\t\t\t\t\t\t";
			if(i==count)
				displayColor(menu[i-1],14);
			else 
				displayMenuItem(menu[i-1]);		
		}
		cout<<"\n\t\t\t\t\t_________________________________________________________________________";
		input=getch();
		if(input==UPPER_ARROW)
		{
			if(count==1)
				count=MENU_SIZE;
			else 
				count--;	
		}		
		else if(input==LOWER_ARROW)
		{
			if(count==MENU_SIZE)
				count=1;
			else
				count++;
		}
		else if(input==ENTER || input == RIGHT_ARROW)
		{
			return count;
		}
	}
}

int userInterface::displayGameLevelMenu()
{
	int flag=1,count=1;
	char input;
	string menu[LEVEL_MENU_SIZE]={"Easy","Medium","Hard","Back"};
	while(flag)
	{
		cout<<endl;
		displayLogo();
		cout<<endl;
		for(int i=1;i<=LEVEL_MENU_SIZE;i++)
		{
			cout<<"\t\t\t\t\t\t\t\t";
			if(i==count)
				displayColor(menu[i-1],YELLOW);
			else 
				displayMenuItem(menu[i-1]);		
		}
		cout<<"\n\t\t\t\t\t_________________________________________________________________________";
		input=getch();
		if(input==UPPER_ARROW)
		{
			if(count==1)
				count=LEVEL_MENU_SIZE;
			else 
				count--;	
		}		
		else if(input==LOWER_ARROW)
		{
			if(count==LEVEL_MENU_SIZE)
				count=1;
			else
				count++;
		}
		else if(input==ENTER || input == RIGHT_ARROW)
		{
			return count;
		}
		clearScreen();
	}
}

int userInterface::askForConfirmation()
{
	int flag=1,count=1;
	char input;
	string menu[CONFIRMATION_MENU_SIZE]={"Yes","No"};
	while(flag)
	{
		
		clearScreen();
		cout<<"\n\n\n\n\n\n\n\n";
		displayLine();
		cout<<endl;
		cout<<"\n\t\t\t\t\t\t\t Do you want to quit the game?\n\n";
		for(int i=1;i<=CONFIRMATION_MENU_SIZE;i++)
		{
			cout<<"\t\t\t\t\t\t\t\t";
			if(i==count)
				displayColor(menu[i-1],YELLOW);
			else 
				displayMenuItem(menu[i-1]);		
		}
		displayLine();
		input=getch();
		if(input==UPPER_ARROW )
		{
			if(count==1)
				count=CONFIRMATION_MENU_SIZE;
			else 
				count--;	
		}		
		else if(input==LOWER_ARROW)
		{
			if(count==CONFIRMATION_MENU_SIZE)
				count=1;
			else
				count++;
		}
		else if(input==ENTER)
		{
			return count;
		}
	}	
}

void userInterface::displayLogo()
{	
	ifstream Reader("logo.txt");          
	string Art = getFileContents (Reader);     	    
	cout<<Art<<endl;	
	Reader.close ();	
}

string userInterface::getFileContents (ifstream& File)
{
    string Lines = "";          
    if (File)                      
    {
	while (File.good ())
	{
	    string TempLine;                  //Temp line
	    getline (File , TempLine);        //Get temp line
	    TempLine += "\n";                      //Add newline character  
	    Lines += TempLine;                     //Add newline
	}
	return Lines;
    }
    else                           
    {
	return "ERROR File does not exist.";
    }
}

void userInterface::displayBoundry()
{
	int i;
	for(i=LEFT_MARGIN; i<=RIGHT_MARGIN;i++)
		cout<<"_";
	for(i=TOP_MARGIN;i<=BOTTOM_MARGIN;i++)
	{
		gotoxy(TOP_MARGIN,i+1);
		cout<<"|";
		gotoxy(RIGHT_MARGIN,i+1);
		cout<<"|";
	}
	cout<<endl;
	for(i=LEFT_MARGIN; i<=RIGHT_MARGIN;i++)
		cout<<"_";	
}

int userInterface::readUserInput(Snake s)
{
	int currentDirection=s.getCurDir();
	int newDirection=currentDirection;
	if(kbhit())
	{
		char input=getch();
		int boost=input;
		if(boost==32)
			return BOOST;
		switch(input)
		{
						
				/*move upward*/
				case 'H':
					newDirection=UP;
					break;
					
				/*move downward*/
				case 'P':
					newDirection=DOWN;
					break;
				
				/*move left*/
				case 'K':
					newDirection=LEFT;
					break;
				
				/*move right*/
				case 'M':
					newDirection=RIGHT;
					break;
				
				/*any other key*/
				default:				
					break;					
		}
	}
	/*check valid change in direction*/
	if(currentDirection==UP && newDirection!=DOWN)
		return newDirection;
	else if(currentDirection==DOWN && newDirection!=UP)
		return newDirection;
	else if(currentDirection==LEFT && newDirection!=RIGHT)
		return newDirection;
	else if(currentDirection==RIGHT && newDirection!=LEFT)
		return newDirection;
	else
		return currentDirection;	
}

void userInterface::displayLine()
{
	for(int i=0; i<RIGHT_MARGIN;i++)
	cout<<"_";
}
void userInterface::displayDottedLine()
{
	for(int i=0; i<RIGHT_MARGIN;i++)
	cout<<"-";
}
void userInterface::displayGameOver()
{
	clearScreen();
	gotoxy(0,22);
	displayLine();
	cout<<endl;
	displayDottedLine();
	gotoxy(50,25);	
	cout<<"GAME OVER!\n\n";
	displayDottedLine();
	cout<<endl;
	displayLine();
	gotoxy(0,50);
	wait();
}

void userInterface::displayCollision(Snake &s)
{
	s.updateHeadSymbol(COLLISION);
	displaySnake(s);
}
	
void userInterface::sleep()
{
	Sleep(1000);
}

void userInterface::exitGame()
{
	exit(0);
}

void userInterface::displayFood(Food f)
{
	gotoxy(f.getX(),f.getY());
	displayColor(f.getSymbol(),YELLOW);
}

void userInterface::displaySnake(Snake s)
{
	vector <Cell> snakeBody=s.getSnakeBody();
	for(int i=snakeBody.size()-1;i>=0;i--)
	{
		gotoxy(snakeBody[i].getX(),snakeBody[i].getY());
		if(i!=0)
			displayColor(snakeBody[i].getSymbol(),CYAN);
		else
			displayColor(snakeBody[i].getSymbol(),RED);
	}		
}
