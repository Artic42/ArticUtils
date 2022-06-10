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
#include <string.h>

#include "Artic42.h"
#include "thoth.h"

/****************************************
*   Private function prototype          *
****************************************/

void getMaskName (char Mask);
void calculateString  (str Message, char mask);
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
char maskBuffer [32];

/****************************************
*   Private constants                   *
****************************************/

#define ENTRY_LIMIT 100

/****************************************
*   Code                                *
****************************************/

struct log* createLog (str name, str path, char mask, int entries)
{
    struct log *logPointer;

    logPointer = malloc (sizeof(struct log));

    strcpy(logPointer->name, name);
    strcpy(logPointer->directoryPath, path);
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

void addEntry (char mask, str message)
{
    struct log *logPointer = firstLog;

    calculateString (message, mask);

    while (logPointer != NULL)
    {
        if (mask & logPointer->mask)
        {
            addLine2File (buffer, logPointer->filePointer);

            logPointer->entriesOnFile++;

            if (logPointer->entriesOnFile >= ENTRY_LIMIT)
            {
                closeLogFile (logPointer);
                logPointer->filePointer = openLogFile (logPointer);
            }
        }
        logPointer = logPointer->nxtLog;
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

void getMaskName (char mask)
{
    switch (mask)
    {
    case INFO:
        strcpy(maskBuffer, "INFO");
        break;
    case DEBUG:
        strcpy(maskBuffer, "DEBUG");
        break;
    case WARNING:
        strcpy(maskBuffer, "WARNING");
        break;
    case SAFETY_WARNING:
        strcpy(maskBuffer, "SAFETY_WARNING");
        break;
    case ALARM:
        strcpy(maskBuffer, "ALARM");
        break;
    case SAFETY_ALARM:
        strcpy(maskBuffer, "SAFETY_ALARM");
        break;
    case SAFETY_ERROR:
        strcpy(maskBuffer, "SAFETY_ERROR");
        break;
    default:
        break;
    }
}

void calculateString  (str Message, char mask)
{
    char partBuffer[MAX_MSG_LENGTH];
    dateTime today = getDateTime();

    getMaskName(mask);
    strcpy(buffer, "");
    // YY/MM/DD HH:MM:SS - MASK - MESSAGE
    sprintf (partBuffer, "%04d/%02d/%02d ", today.year, today.month, today.day);
    strcat (buffer, partBuffer);

    sprintf (partBuffer, "%02d:%02d:%02d - ", today.hour, today.min, today.sec);
    strcat (buffer, partBuffer);

    strcat (buffer, maskBuffer);
    strcat (buffer, " - ");
    strcat (buffer, Message);
}

void addLog2List (struct log* logPointer)
{
    if (firstLog == NULL) { firstLog = logPointer; }
    logPointer->prvLog = lastLog;
    if (lastLog != NULL) { lastLog->nxtLog = logPointer; }
    lastLog = logPointer;
}

void removeLog2List (struct log* logPointer)
{
    logPointer->prvLog->nxtLog = logPointer->nxtLog;
    logPointer->nxtLog->prvLog = logPointer->prvLog;
    if (logPointer->nxtLog == NULL) {lastLog = logPointer->prvLog;}
    if (logPointer->prvLog == NULL) {firstLog = logPointer->nxtLog;}
}

FILE* openLogFile (struct log* logPointer)
{
    dateTime today = getDateTime();
    char partBuffer[MAX_MSG_LENGTH], cmdDirCreation[MAX_PATH_LENGTH + 50];

    strcpy(buffer, logPointer->directoryPath);
    strcat(buffer, "/");
    strcat(buffer, logPointer->name);

    sprintf(partBuffer, "_%04d%02d%02d_%02d%02d%02d.log", today.year, today.month, today.day, today.hour, today.min, today.sec);
    strcat(buffer, partBuffer);

    strcpy(cmdDirCreation, "mkdir -p ");
    strcat(cmdDirCreation, logPointer->directoryPath);
    system(cmdDirCreation);

    return fopen(buffer, "w");
    //return openFile2Write (buffer);
}

void closeLogFile (struct log* logPointer)
{
    closeFile (logPointer->filePointer);
}