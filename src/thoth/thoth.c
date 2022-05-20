/*
File Name:   Hermes.c
//
Compiler:    GCC
Author:      Artic42
Description: This is library helps create log file in UNIX like systems
Tested on:    Raspberry Pi OS and wsl2
*/

/****************************************
*	Include                             *
****************************************/
#include <stdio.h>

#include "Artic42.h"
#include "thoth.h"

/****************************************
*   Private function prototype          *
****************************************/

void calculateString (string Message, char mask);
void addLog2List (log* logPointer);
void removeLog2List (log* logPointer);
void openLogFile (log* logPointer);
void closeLogFile (log* logPointer);

/****************************************
*   Private global variables            *
****************************************/

log *first = NULL;
log *last = NULL;

/****************************************
*   Code                                *
****************************************/



