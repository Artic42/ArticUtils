/*
File Name:   Thoth.h
//
Compiler:    gcc
Author:      Artic42
Description: Header file of thoth library
Tested on:    WSL 2 Debian
*/

#ifndef THOTH_H
#define THOTH_H

/****************************************
*	Include                             *
****************************************/

#include "Artic42.h"

/****************************************
*	Public Struct                       * 
****************************************/

struct log
{
    char name [MAX_NAME_LENGTH];
    char directoryPath [MAX_PATH_LENGTH];
    FILE *filePointer;
    char mask;
    int entriesOnFile;
    struct log *prvLog;
    struct log *nxtLog;
};

/****************************************
*	Public Function Prototype           * 
****************************************/

struct log *createLog (char name, string path, char mask, int entries);
void closeLog (struct log* logPointer);
void closeAllLog (void);
void addEntry (string Message, char mask);
void addMask (struct log* logPointer, char mask);
void delMask (struct log* logPointer, char mask);

/****************************************
*	Public Constants                    * 
****************************************/

#define MAX_NAME_LENGTH 512
#define MAX_PATH_LENGTH 1024
#define MAX_MSG_LENGTH 1024
#define MAX_FILE_LENGTH 1024

//Masks
#define INFO 0x01
#define DEBUG 0x02
#define WARNING 0X04
#define SAFETY_WARNING 0X08
#define ALARM 0X10
#define SAFETY_ALARM 0X20
#define SAFERTY_ERROR 0X40



#endif