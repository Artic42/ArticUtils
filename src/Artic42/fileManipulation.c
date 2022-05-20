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

void addLine2File (string line, FILE* FP)
{
    fprintf (FP, "%s\n", line);
}