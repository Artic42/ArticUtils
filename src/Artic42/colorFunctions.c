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
*	Color functions                          *
***********************************************/

int convertColorToPercent (int8b color)
{
    int result = color * 1000;
    return result/255;
}

int8b convertColorTo255 (int color)
{
    int result = color * 255;
    return result/1000;
}

color defineColorNoOpacity (int8b colorValues[3])
{
    color result;
    result.red = colorValues[1];
    result.green = colorValues[2];
    result.blue = colorValues[3];
    result.opacity = 255;
    return result;
}

color defineColorWithOpacity (int8b colorValues[4])
{
    color result;
    result.red = colorValues[1];
    result.green = colorValues[2];
    result.blue = colorValues[3];
    result.opacity = colorValues[4];
    return result;
}