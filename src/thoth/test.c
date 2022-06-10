/*
File Name:   Hermes.c
//
Compiler:    GCC
Author:      Artic42
Description: Creates a small program , this program checks
             that all the funcion on the library work properly
Tested on:    Raspberry Pi OS and wsl2
*/

/****************************************
*	Include                             *
****************************************/

#include <stdio.h>
#include <string.h>

#include "Artic42.h"
#include "thoth.h"

/****************************************
*	Private Function Prtotype           *
****************************************/

int main (void);

/****************************************
*	Code                                *
****************************************/

int main (void)
{
    // Create 3 logs with different masks
    struct log* log1 = createLog ("Log1", "/home/artic/ArticUtils/logs", INFO, 3);
    struct log* log2 = createLog ("Log2", "/home/artic/ArticUtils/logs", DEBUG, 3);
    struct log* log3 = createLog ("Log3", "/home/artic/ArticUtils/logs", INFO | DEBUG, 3);
    // Send a message that should appear in 2
    addEntry (DEBUG, "This message should appear on 2 and 3");
    addEntry (INFO, "This message should appear on 1 and 3");
    addEntry (SAFETY_ALARM, "This message should not appear");
    // Add a mask and eliminate a mask
    addMask (log1, DEBUG);
    delMask (log3, DEBUG);
    // Send a message with the mask you elimiante and create it
    addEntry (DEBUG, "This message should appear on 2 and 1");
    addEntry (INFO, "This message should appear on 1 and 3");
    addEntry (SAFETY_ALARM, "This message should not appear");
    // Close the middle log
    closeLog (log2);
    // Send a message for both logs
    addEntry (DEBUG, "This message should appear on 1");
    // Eliminate last
    closeLog (log3);
    // Send a message for last log
    addEntry (INFO, "This message should appear on 1");
    // Eliminate first 
    closeLog (log1);
    // Send a message and check that it doesn crash
    addEntry (SAFETY_ALARM, "This message should not appear");
}