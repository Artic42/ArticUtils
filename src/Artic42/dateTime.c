/*
File Name:   Artic42.c
//
Compiler:    gcc
Author:      Artic42
Description: Functions related to operation with characters
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
*	Date and time functions                    *
***********************************************/

dateTime getDateTime (void)
{
    time_t t = time (NULL);
    struct tm T = *localtime (&t);
}

boolean isHigher (dateTime date1, dateTime date2)
{

}

boolean isEqual (dateTime date1, dateTime date2)
{

}