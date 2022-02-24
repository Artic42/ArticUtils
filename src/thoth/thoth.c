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
*   Structures                          *
****************************************/

typedef struct {
    char name[128];
    int8b mask;
    FILE *file;
    log *nxt;
} log;

/****************************************
*   Private function prototype          *
****************************************/



/****************************************
*   Private global variables            *
****************************************/

log *first = NULL;
log *last = NULL;

/****************************************
*   Code                                *
****************************************/

void createLog (string name, char logMask, string path)
{
    log* tempPtr;
    tempPtr = malloc (sizeof(log));
    if (&last == NULL) { first = tempPtr;}
    else               { last -> nxt = tempPtr;}
    last = tempPtr;
    tempPtr->file = fopen (path, 'w');
    tempPtr->mask = logMask;
}


