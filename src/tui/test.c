/****************************************
*	Include                             *
****************************************/

#include <ncurses.h>
#include <unistd.h>
#include "tui.h"

/****************************************
*	Private Function Prototype           *
****************************************/

int main (void);

/****************************************
*	Private Definitions	                *
****************************************/

#define PAIR_1 10
#define PAIR_2 11

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
    WINDOW *mainWindow = drawMainWindow(20, 20, PAIR_1);
    WINDOW *subWindow = drawSubWindow (mainWindow, 10, 10, PAIR_2, 5, 5);
    sleep(60);
    finishTUI();
}