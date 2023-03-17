#ifndef TUI_H
#define TUI_H

/****************************************
*	Include                             *
****************************************/

#include <ncurses.h>
#include <panel.h>


#include "Artic42.h"

/****************************************
*	Public Constants                    * 
****************************************/

#define MAX_WIDTH 300

/****************************************
*	Public Struct                       * 
****************************************/


/****************************************
*	Public Varaibles                    * 
****************************************/

extern char bufferTUI[MAX_WIDTH];

/****************************************
*	Public Function Prototype           * 
****************************************/

WINDOW *startTUI (void);
void finishTUI (void);
WINDOW *drawMainWindow (int width, int height, int color);
WINDOW *drawSubWindow (WINDOW *parentWindow, int width, int height, int color, int posY, int posX);
void writeBufferInWindow (WINDOW *window, int posY, int posX);
void writeBuffereInLineCentered (WINDOW *window, int lineNumber);
void setWindowColor (WINDOW *window, int color);
void activateBoldInWindow (WINDOW *window);
void deactivateBoldInWindow (WINDOW *window);
void defineColorPair (int8b pairID, int8b background, int8b foreground);
void defineColor (int8b colorID, color *colorValue);


#endif