#ifndef __GETCH__
#define __GETCH__
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

/* Reads a character directly from the console without buffer, and without echo. */
int getch(void);

/* Reads a character directly from the console without buffer, but with echo */
int getche(void);


/* Determines if a keyboard key was pressed */
int kbhit(void);


/* Clears data from the console screen */
void clrscr(void);

#endif
