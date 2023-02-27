/*
File Name:   tui.c
//
Compiler:    GCC
Author:      Artic42
Description: This is a library to create text interfaces with ncurses.
*/

/****************************************
*	Include                             *
****************************************/

#include <ncurses.h>



/****************************************
*	Private Function Prototype           *
****************************************/

WINDOW *createWindowCentered (int width, int height);
WINDOW *createSubWindow (WINDOW *origWindow, int height, int width, int posY, int posX);
void drawWindowBorder (WINDOW *window);

/****************************************
*	Private Definitions	                *
****************************************/



/****************************************
*	Private Variables                   *
****************************************/



/****************************************
*	Code                                *
****************************************/

WINDOW *startTUI(void)
{
    WINDOW *window = initscr();
    if (has_colors()) { start_color (); }
    return window;
}

WINDOW *drawMainWindow (int width, int height, int color)
{
    WINDOW *window = createWindowCentered(height, width);
    wattr_set (window, A_BOLD, color, NULL);
    drawWindowBorder (window);
    wrefresh(window);
    return window;
}

WINDOW *createWindowCentered (int width, int height)
{
    long row, col;
    getmaxyx (stdscr, row, col);
    return newwin (height, width, (row-height)/2, (col-width)/2);
}

WINDOW *createSubWindow (WINDOW *origWindow, int height, int width, int posY, int posX)
{
    return derwin (origWindow, height, width, posY, posX);
}

void drawWindowBorder (WINDOW *window)
{
    wborder (window, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
}