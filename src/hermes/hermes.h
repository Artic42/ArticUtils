/*
File Name:   Hermes.h
//
Compiler:    gcc
Author:      Artic42
Description: Header file of Hermes library
Tested on:    Raspberry Pi OS
*/

#ifndef HERMES_H
#define HERMES_H

/****************************************
*	Include                             *
****************************************/

#include "Artic42.h"

/****************************************
*	Public Function Prototype           * 
****************************************/

void createFile (str path);
void deleteFile (str path);
void createDirectory (str path);
void deleteDirectory (str path);
void bool2file (str  path, boolean value);
boolean file2bool (str  path);
void int2file (str  path, int value);
int file2int (str  path);
void float2file (str path, float value);
float file2float (str path);
void str2file (str path, str value);
void file2str (str path, str result);
void file2print (str path);
void char2file (str path, char value);
char file2char (str path, int offset);


#endif