/*
File Name:   Artic42.c
//
Compiler:    gcc
Author:      Artic42
Description: Functions related to operation with integers
Tested on:   Windows Subsystem for Linux
*/

/************************************************
*   Include                                     *
************************************************/

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
*	Integer functions                          *
***********************************************/

int calculateAbsolute (int number)
{
    if (isNumberNegative(number)) { return number * (-1); }
    else                          { return number;  }
}

int returnHigher (int number1, int number2)
{
    if (number1 > number2)  { return number1; }
    else                    { return number2; }
}

int returnLower (int number1, int number2)
{
    if (number1 < number2)  { return number1; }
    else                    { return number2; }
}

boolean isNumberZero (int number)
{
    return number == 0;
}

boolean isNumberPositive (int number)
{
    return number >= 0;
}

boolean isNumberNegative (int number)
{ 
    return number < 0;
}

int intAbsolute (int value)
{
    if (value < 0)  { return value * (-1); }
    else            { return value; }
}

int intGiveMax (int value1, int value2)
{
    if (value1 < value2) { return value2; }
    else                 { return value1; }
}

int intGiveMin (int value1, int value2)
{
    if (value1 > value2) { return value2; }
    else                 { return value1; }
}