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
#include <string.h>

#include "tui.h"




/****************************************
*	Private Function Prototype           *
****************************************/

WINDOW *createWindowCentered (int width, int height);
WINDOW *createSubWindow (WINDOW *origWindow, int height, int width, int posY, int posX);
void drawWindowBorder (WINDOW *window);
void fillWindow (WINDOW *window);
int getWindowWidth (WINDOW *window);

/****************************************
*	Private Definitions	                *
****************************************/


/****************************************
*	Private Variables                   *
****************************************/

char bufferTUI[MAX_WIDTH];

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
    WINDOW *window = createWindowCentered( width,  height);
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

void writeBufferInWindow (WINDOW *window, int posY, int posX)
{
    mvwprintw (window, posY, posX, "%s", bufferTUI);
    wrefresh (window);
}

void writeBuffereInLineCentered (WINDOW *window, int lineNumber)
{
    int windowWidth = getWindowWidth (window);
    int bufferLength = strlen (bufferTUI);
    int distance = (windowWidth - bufferLength)/2;
    writeBufferInWindow (window, lineNumber, distance);
}

void defineColorPair (int8b pairID, int8b background, int8b foreground)
{
    init_pair (pairID, foreground, background);
}

void defineColor (int8b colorID, color *colorValue)
{
    int red100 = convertColorToPercent (colorValue->red);
    int green100 = convertColorToPercent (colorValue->green);
    int blue100 = convertColorToPercent (colorValue->blue);
    init_color (colorID, red100, green100, blue100);
}

WINDOW *createWindowCentered (int width, int height)
{
    long row, col;
    getmaxyx (stdscr, row, col);
    WINDOW *result = newwin (height, width, (row-height)/2, (col-width)/2);
    return result;
}

WINDOW *createSubWindow (WINDOW *origWindow, int height, int width, int posY, int posX)
{
    return derwin (origWindow, height, width, posY, posX);
}

void setWindowColor (WINDOW *window, int color)
{
    wattr_set(window, 0, color, NULL);
}

void activateBoldInWindow (WINDOW *window)
{
    wattr_on (window, A_BOLD, NULL);
}

void deactivateBoldInWindow (WINDOW *window)
{
    wattr_off (window, A_BOLD, NULL);
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

int getWindowWidth (WINDOW *window)
{
    int windowWidth, windowHeigth;
    getmaxyx (window, windowHeigth, windowWidth);
    return windowWidth;
}