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



/****************************************
*	Public Struct                       * 
****************************************/


/****************************************
*	Public Function Prototype           * 
****************************************/

WINDOW *startTUI (void);
WINDOW *drawMainWindow (int width, int height, int color);
void defineColorPair (int pairID, int background, int foreground);
void defineColor (int colorID, int red, int green, int blue);


#endif