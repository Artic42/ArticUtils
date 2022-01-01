/*
File Name:   Hermes.c
//
Compiler:    GCC
Author:      Artic42
Description: This is library to store variable in files in a UNIX system.
Tested on:    Raspberry Pi OS and wsl2
*/

/****************************************
*	Include                             *
****************************************/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "lib/Artic42.h"
#include "Hermes.h"

/****************************************
*	Private Function Prtotype           *
****************************************/


/****************************************
*	Private Definitions	                *
****************************************/

#define FILES_EXIST 0

/****************************************
*	Private Variables                   *
****************************************/

/****************************************
*	Code                                *
****************************************/

//  createFiles
//
//  Creates a file in the specified path.
//  if the files exist only changes modify data no content

void createFile (string path)
{
    char command [1024] = "touch ";
    strncat (command, path, sizeof(command));
    system (command);
}

// deleteFile
//
// Deletes the file in the specified path, in doesn't delete directory unless empty

void deleteFile (string path)
{
    char command [1024]= "rm -f ";
    strncat (command, path, sizeof(command));
    system (command);
}

void bool2file (string  path, bool value)
{
    if (value) { createFile (path);}
    else       { deleteFile (path);}
}

bool file2bool (string path)
{
    if (access (path, F_OK) == FILES_EXIST) { return 1; }
    else                                    { return 0; }
}

void int2file (string path, int value)
{
    FILE *filePtr = NULL;
    filePtr = fopen (path, "w");
    fprintf (filePtr, "%d", value);
    fclose (filePtr);
}

int file2int (string path)
{
    int result;
    FILE *filePtr = NULL;
    filePtr = fopen (path, "r");
    fscanf (filePtr, "%d", &result);
    fclose (filePtr);
    return result;
}

void float2file (string path, float value)
{
    FILE *filePtr = NULL;
    filePtr = fopen (path, "w");
    fprintf (filePtr, "%f", value);
    fclose (filePtr);
}

float file2float (string path)
{
    float result;
    FILE *filePtr = NULL;
    filePtr = fopen (path, "r");
    fscanf (filePtr, "%f", &result);
    fclose (filePtr);
    return result;
}

void string2file (string path, string value)
{
    FILE *filePtr = NULL;
    filePtr = fopen (path, "w");
    fprintf (filePtr, value);
    fclose(filePtr);
}

void file2print (string path)
{
    char buffer [20480];
    FILE *filePtr = NULL;
    filePtr = fopen (path, "r");
    fgets (buffer, 20480, filePtr);
    printf ("%s \n", buffer);
    fclose (filePtr);
}

void char2file (string path, char value)
{
    FILE *filePtr = NULL;
    filePtr = fopen (path, "w");
    fprintf (filePtr, "%c", value);
    fclose (filePtr);
}

char file2char (string path, int offset)
{
    char buffer [20480];
    FILE *filePtr = NULL;
    filePtr = fopen (path, "r");
    fgets (buffer, 20480, filePtr);
    return buffer [offset];
}