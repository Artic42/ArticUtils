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
*	Public Function Prototype           * 
****************************************/

void createLog (string name, char logMask, string path);
void add2Mask (string name, char mask);
void delete2Mask (string name, char mask);
void addEntry (char messageMask, string message);

/****************************************
*	Public Constants                    * 
****************************************/

#define m 1

#endif