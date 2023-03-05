/*
File Name:   Artic42.h
//
Compiler:	 gcc
Author:		 Artic42
Description: Header were I include a series of common macros and definitions that I use in all projects
*/

#ifndef ARTIC42_H
#define ARTIC42_H

#include <stdio.h>
/**************************************
*   Personal definitions              *
**************************************/

// Variable types
typedef char boolean;
typedef const char *str;
typedef char int8b;

#define BTRUE 1
#define BFALSE 0

/***********************************************
*	Personal Structures                        *
***********************************************/

typedef struct {
    int year;
    int8b month;
    int8b day;
    int8b hour;
    int8b min;
    int8b sec;
} dateTime;

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

//File manipulation
void addLine2File (str line, FILE* FP);
FILE* openFile2Write (str path);
FILE* openFile2Read (str path);
FILE* openFile2Append (str path);
void createDirectory (str path);
char pathExists (str path);
void closeFile (FILE* FP);

//Date and time
dateTime getDateTime (void);
boolean isHigher (dateTime date1, dateTime date2);
boolean dayIsEqual (dateTime date1, dateTime date2);\

//ColorFunctions
int convertColorToPercent (int8b color);
int8b convertColorTo255 (int color);

#endif