/*
File Name:   Artic42.h
//
Compiler:	 gcc
Author:		 Artic42
Description: Header were I include a series of common macros and definitions that I use in all projects
*/

#ifndef ARTIC42_H
#define ARTIC42_H

/**************************************
*   Personal definitions              *
**************************************/

// Variable types
typedef char boolean;
typedef const char* string;
typedef char int8b;

#define BTRUE 1
#define BFALSE 0

/***********************************************
*	Personal Structures                        *
***********************************************/

/************************************************
*	Private Function Prtotype                   *
************************************************/


//Character functions
char makeUpperCase (char character);
char makeLowerCase (char character);
int8b makeCharInt (char character);
boolean characterBetweenLetters (char character, char upperLimit, char lowerLimit);
boolean characterIsLetter (char character);
boolean characterIsLowerCase (char character);
boolean characterIsUpperCase (char character);
boolean characterIsNumber (char character);

//Integer functions
int calculateAbsolute (int number);
int returnHigher (int number1, int number2);
int returnLower (int number1, int number2);
boolean isNumberZero (int number);
boolean isNumberPositive (int number);
boolean isNumberNegative (int number);
int intAbsolute (int value);
int intGiveMax (int value1, int value2);
int intGiveMin (int value1, int value2);

#endif