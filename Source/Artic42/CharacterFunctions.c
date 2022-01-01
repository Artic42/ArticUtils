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
*	Character functions                        *
***********************************************/

char makeUpperCase (char character)
{
    if (characterIsLowerCase (character)) { return character - 32; }
    else                                  { return -1;             }
}

char makeLowerCase (char character)
{
    if (characterIsUpperCase (character)) { return character + 32; }
    else                                  { return -1;             }
}

int8b makeCharInt (char character)
{
    return character - 48;
}

boolean characterBetweenLetters (char character, char upperLimit, char lowerLimit)
{
    return (character <= upperLimit) && (character >= lowerLimit);
}

boolean characterIsLetter (char character)
{
    return characterIsLowerCase (character) || characterIsUpperCase (character);
}

boolean characterIsLowerCase (char character)
{
    return characterBetweenLetters (character, 'z', 'a');
}

boolean characterIsUpperCase (char character)
{
    return characterBetweenLetters (character, 'Z', 'A');
}

boolean characterIsNumber (char character)
{
    return characterBetweenLetters (character, '9', '0');
}

