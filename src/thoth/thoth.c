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

void getMaskName (int mask);
void calculateString  (str Message, int mask);
void addLog2List (struct log* logPointer);
void removeLog2List (struct log* logPointer);
FILE* openLogFile (struct log* logPointer);
void calculateFirstLine (struct log* logPointer, dateTime today);
void closeLogFile (struct log* logPointer);

/****************************************
*   Private global variables            *
****************************************/

struct log *firstLog = NULL;
struct log *lastLog = NULL;
char messageBuffer [MAX_MSG_LENGTH+512];
char pathBuffer [MAX_PATH_LENGTH+MAX_NAME_LENGTH+50];
char maskBuffer [32];
char lineBuffer [MAX_FILE_LENGTH+50];

/****************************************
*   Private constants                   *
****************************************/

#define ENTRY_LIMIT 100

/****************************************
*   Code                                *
****************************************/

struct log* createLog (str name, str path, int mask, int entries)
{
    struct log *logPointer;

    logPointer = malloc (sizeof(struct log));

    strcpy(logPointer->name, name);
    strcpy(logPointer->directoryPath, path);
    logPointer->mask = mask;
    logPointer->entriesOnFile = 0;
    logPointer->entryLimit = entries;
    logPointer->nxtLog = NULL;
    logPointer->prvLog = NULL;
    logPointer->filePointer = openLogFile (logPointer);

    addLog2List (logPointer);

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

void addEntry (int mask, str message)
{
    struct log *logPointer = firstLog;

    calculateString (message, mask);

    while (logPointer != NULL)
    {
        if (mask & logPointer->mask)
        {
            addLine2File (messageBuffer, logPointer->filePointer);

            logPointer->entriesOnFile++;

            if (logPointer->entriesOnFile >= logPointer->entryLimit)
            {
                logPointer->entriesOnFile = 0;
                closeLogFile (logPointer);
                logPointer->filePointer = openLogFile (logPointer);
            }
        }
        logPointer = logPointer->nxtLog;
    }
}

void addMask (struct log* logPointer, int mask)
{
    logPointer->mask = logPointer->mask | mask;
}

void delMask (struct log* logPointer, int mask)
{
    logPointer->mask = logPointer->mask & (~mask);
}

void getMaskName (int mask)
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
    case COMUNNICATION_SEND:
        strcpy(maskBuffer, "COMUNNICATION_SEND");
        break;
    case COMUNNICATION_REC:
        strcpy(maskBuffer, "COMUNNICATION_REC");
        break;
    case ERROR:
        strcpy(maskBuffer, "ERROR");
        break;
    case HERMES:
        strcpy(maskBuffer, "THOTH");
        break;
    default:
        break;
    }
}

void calculateString  (str Message, int mask)
{
    char partBuffer[MAX_MSG_LENGTH];
    dateTime today = getDateTime();

    getMaskName(mask);
    // YY/MM/DD HH:MM:SS - MASK - MESSAGE
    sprintf (partBuffer, "%04d/%02d/%02d ", today.year, today.month, today.day);
    strcpy (messageBuffer, partBuffer);

    sprintf (partBuffer, "%02d:%02d:%02d - ", today.hour, today.min, today.sec);
    strcat (messageBuffer, partBuffer);

    strcat (messageBuffer, maskBuffer);
    strcat (messageBuffer, " - ");
    strcat (messageBuffer, Message);
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
    if (logPointer->prvLog != NULL) {logPointer->prvLog->nxtLog = logPointer->nxtLog;}
    if (logPointer->nxtLog != NULL) {logPointer->nxtLog->prvLog = logPointer->prvLog;}
    if (logPointer->nxtLog == NULL) {lastLog = logPointer->prvLog;}
    if (logPointer->prvLog == NULL) {firstLog = logPointer->nxtLog;}
}

FILE* openLogFile (struct log* logPointer)
{
    FILE* FP;
    dateTime today = getDateTime();
    char partBuffer[MAX_MSG_LENGTH + 50];

    strcpy(pathBuffer, logPointer->directoryPath);
    strcat(pathBuffer, "/");
    strcat(pathBuffer, logPointer->name);

    sprintf(partBuffer, "_%04d%02d%02d_%02d%02d%02d.log", today.year, today.month, today.day, today.hour, today.min, today.sec);
    strcat(pathBuffer, partBuffer);

    createDirectory (logPointer->directoryPath);

    if (pathExists(pathBuffer) == BFALSE)
    {
        FP = openFile2Write (pathBuffer);
        calculateFirstLine (logPointer, today);
        addLine2File (lineBuffer, FP);
    }
    else
    {
        FP = openFile2Append (pathBuffer);
    }
    return FP;
}

void calculateFirstLine (struct log* logPointer, dateTime today)
{
    char dateString1 [32], dateString2 [32];
    sprintf(dateString1, "%04d/%02d/%02d ", today.year, today.month, today.day);
    sprintf (dateString2, "%02d:%02d:%02d", today.hour, today.min, today.sec);
    strcpy (lineBuffer, logPointer->name);
    strcat (lineBuffer, " - ");
    strcat (lineBuffer, dateString1);
    strcat (lineBuffer, dateString2);

}

void closeLogFile (struct log* logPointer)
{
    closeFile (logPointer->filePointer);
}