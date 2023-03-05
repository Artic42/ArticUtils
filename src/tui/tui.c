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

#include <Artic42.h>
#include <ncurses.h>



/****************************************
*	Private Function Prototype           *
****************************************/

WINDOW *createWindowCentered (int width, int height);
WINDOW *createSubWindow (WINDOW *origWindow, int height, int width, int posY, int posX);
void drawWindowBorder (WINDOW *window);
void fillWindow (WINDOW *window);

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
    refresh();
    return window;
}

void finishTUI (void)
{
    endwin();
}

WINDOW *drawMainWindow (int width, int height, int color)
{
    WINDOW *window = createWindowCentered(height, width);
    wattr_set (window, A_BOLD, color, NULL);
    fillWindow (window);
    drawWindowBorder (window);
    wrefresh(window);
    return window;
}

WINDOW *drawSubWindow (WINDOW *parentWindow, int width, int height, int color, int posY, int posX)
{
    WINDOW *window = createSubWindow (parentWindow, height, width, posY, posX);
    wattr_set (window, 0, color, NULL);
    fillWindow (window);
    wrefresh (window);
    return window;
}

void defineColorPair (int8b pairID, int8b background, int8b foreground)
{
    init_pair (pairID, foreground, background);
}

void defineColor (int8b colorID, int8b red, int8b green, int8b blue)
{
    init_color (colorID, red, green, blue);
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

void fillWindow (WINDOW *window)
{
    int rows = getmaxy (window);
    int cols = getmaxx (window);
    for (int i=0; i<=rows; i++)
    {
        for (int j=0; j<=cols; j++)
        {
            mvwprintw(window, i, j, " ");
        }
    }
}

