/*
File Name:   Artic42.c
//
Compiler:    gcc
Author:      Artic42
Description: Functions related to operation with file manipulation
Tested on:   Windows Subsystem for Linux
*/

/************************************************
*   Include                                     *
************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "Artic42.h"

/************************************************
*	Private Function Prtotype                   *
************************************************/

/***********************************************
*	Private Constants                          *
***********************************************/

/***********************************************
*	Private Structures                         *
***********************************************/

/***********************************************
*	Private Variables                          *
***********************************************/

/***********************************************
*	File Manipulation                          *
***********************************************/

void addLine2File (str line, FILE* FP)
{
    fprintf (FP, "%s\n", line);
    fflush (FP);
}

FILE* openFile2Write (str path)
{
    return fopen (path, "w");
}

FILE* openFile2Read (str path)
{
    return fopen (path, "r");
}

FILE* openFile2Append (str path)
{
    return fopen (path, "a");
}

void createDirectory (str path)
{
    if (pathExists(path) == BFALSE)
    {
        char cmdDirCreation[2048];
        strcpy(cmdDirCreation, "mkdir -p ");
        strcat(cmdDirCreation, path);
        system(cmdDirCreation);
    }
}

char pathExists (str path)
{
    if (access(path, F_OK) == 0) { return BTRUE;}
    else { return BFALSE; }
}

void closeFile (FILE* FP)
{
    fclose (FP);
}