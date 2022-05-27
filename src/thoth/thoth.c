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
#include <stdlib.h>

#include "Artic42.h"
#include "thoth.h"

/****************************************
*   Private function prototype          *
****************************************/

void calculatestr (str Message, char mask);
void addLog2List (struct log* logPointer);
void removeLog2List (struct log* logPointer);
FILE* openLogFile (struct log* logPointer);
void closeLogFile (struct log* logPointer);

/****************************************
*   Private global variables            *
****************************************/

struct log *firstLog = NULL;
struct log *lastLog = NULL;
char buffer [MAX_MSG_LENGTH+512];

/****************************************
*   Private constants                   *
****************************************/

#define ENTRY_LIMIT 100

/****************************************
*   Code                                *
****************************************/

struct log *createLog (str name, str path, char mask)
{
    struct log *logPointer;

    logPointer = malloc (sizeof(struct log));

    logPointer->name = name;
    logPointer->directoryPath = path;
    logPointer->mask = mask;

    addLog2List (logPointer);

    logPointer->filePointer = openLogFile (logPointer);

    return logPointer;
}

void closeLog (struct log *logPointer)
{
    closeLogFile (logPointer);
    removeLog2List (logPointer);
    free (logPointer);
}

void closeAllLogs (void)
{
    struct log *logPointer = firstLog;

    while (logPointer != NULL)
    {
        struct log *nxtPointer = logPointer->nxtLog;
        closeLog (logPointer);
        logPointer = nxtPointer;
    }
}

void addEntry (str message, char mask)
{
    struct log *logPointer = firstLog;

    calculatestr (message, mask);

    while (logPointer != NULL)
    {
        if (mask && logPointer->mask)
        {
            addLine2File (buffer, logPointer->filePointer);

            logPointer->entriesOnFile++;

            if (logPointer->entriesOnFile >= ENTRY_LIMIT)
            {
                closeLogFile (logPointer);
                openLogFile (logPointer);
            }

            logPointer = logPointer->nxtLog;
        }
    }
}

void addMask (struct log* logPointer, char mask)
{
    logPointer->mask = logPointer->mask | mask;
}

void delMask (struct log* logPointer, char mask)
{
    logPointer->mask = logPointer->mask & (~mask);
}