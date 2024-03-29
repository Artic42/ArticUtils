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

#include "Artic42.h"
#include "hermes.h"

/****************************************
*	Private Function Prototype           *
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

void createFile (str path)
{
    char command [1024] = "touch ";
    strncat (command, path, sizeof(command));
    system (command);
}

// deleteFile
//
// Deletes the file in the specified path, in doesn't delete directory unless empty

void deleteFile (str path)
{
    char command [1024]= "rm -f ";
    strncat (command, path, sizeof(command));
    system (command);
}

void bool2file (str  path, boolean value)
{
    if (value) { createFile (path);}
    else       { deleteFile (path);}
}

boolean file2bool (str path)
{
    if (access (path, F_OK) == FILES_EXIST) { return 1; }
    else                                    { return 0; }
}

void int2file (str path, int value)
{
    FILE *filePtr = NULL;
    filePtr = fopen (path, "w");
    fprintf (filePtr, "%d", value);
    fclose (filePtr);
}

int file2int (str path)
{
    int result;
    FILE *filePtr = NULL;
    filePtr = fopen (path, "r");
    if (filePtr == NULL)
    {
        printf ("File %s couldn't be openned.", path);
        return -1;
    }
    else
    {
        fscanf (filePtr, "%d", &result);
        fclose (filePtr);
        return result;
    }
}

void float2file (str path, float value)
{
    FILE *filePtr = NULL;
    filePtr = fopen (path, "w");
    fprintf (filePtr, "%f", value);
    fclose (filePtr);
}

float file2float (str path)
{
    float result;
    FILE *filePtr = NULL;
    filePtr = fopen (path, "r");
    if (filePtr == NULL)
    {
        printf ("File %s couldn't be openned.", path);
        return -1;
    }
    else
    {
        fscanf (filePtr, "%f", &result);
        fclose (filePtr);
        return result;
    }
}

void str2file (str path, str value)
{
    FILE *filePtr = NULL;
    filePtr = fopen (path, "w");
    fprintf (filePtr, "%s", value);
    fclose(filePtr);
}

void file2print (str path)
{
    char buffer [20480];
    FILE *filePtr = NULL;
    filePtr = fopen (path, "r");
    if (filePtr == NULL)
    {
        printf ("File %s couldn't be openned.", path);
    }
    else
    {
        fgets (buffer, 20480, filePtr);
        printf ("%s \n", buffer);
        fclose (filePtr);
    }
}

void char2file (str path, char value)
{
    FILE *filePtr = NULL;
    filePtr = fopen (path, "w");
    fprintf (filePtr, "%c", value);
    fclose (filePtr);
}

char file2char (str path, int offset)
{
    char buffer [20480];
    FILE *filePtr = NULL;
    filePtr = fopen (path, "r");
    if (filePtr == NULL)
    {
        printf ("File %s couldn't be openned.", path);
        return -1;
    }
    else
    {
        fgets (buffer, 20480, filePtr);
        return buffer [offset];
    }
}