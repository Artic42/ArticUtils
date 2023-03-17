/****************************************
*	Include                             *
****************************************/

#include <ncurses.h>
#include <unistd.h>
#include "tui.h"
#include "Artic42.h"

/****************************************
*	Private Function Prototype           *
****************************************/

int main (void);

/****************************************
*	Private Definitions	                *
****************************************/

#define PAIR_1 10
#define PAIR_2 11
#define PAIR_3 12

/****************************************
*	Private Variables                   *
****************************************/



/****************************************
*	Code                                *
****************************************/

int main (void)
{
    startTUI();
    defineColorPair(PAIR_1,COLOR_BLUE, COLOR_WHITE);
    defineColorPair(PAIR_2,COLOR_GREEN, COLOR_WHITE);
    defineColorPair(PAIR_3, COLOR_RED, COLOR_WHITE);
    WINDOW *mainWindow = drawMainWindow(40, 40, PAIR_1);
    WINDOW *subWindow = drawSubWindow (mainWindow, 20, 20, PAIR_2, 10, 10);
    setWindowColor (subWindow, PAIR_3);
    activateBoldInWindow (subWindow);
    sprintf (bufferTUI, "Hello, world!!!!!!");
    writeBuffereInLineCentered (subWindow, 0);
    deactivateBoldInWindow (subWindow);
    sprintf (bufferTUI, "NOT BOLD");
    writeBufferInWindow (mainWindow, 1, 1);
    sleep(30);
    finishTUI();
}