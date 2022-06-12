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
#include <time.h>

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
       dateTime s_dateTime;
    
    struct tm T = *localtime (&t);

    s_dateTime.day = T.tm_mday;
    s_dateTime.month = T.tm_mon;
    s_dateTime.year = T.tm_year + 1900;
    s_dateTime.hour = T.tm_hour;
    s_dateTime.min = T.tm_min;
    s_dateTime.sec = T.tm_sec;

    return s_dateTime;
}

boolean isHigher (dateTime date1, dateTime date2)
{
    return BTRUE;
}

boolean isEqual (dateTime date1, dateTime date2)
{
    return BTRUE;
}