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

color defineColorNoOpacity (int8b red, int8b green, int8b blue)
{
    color result;
    result.red = red;
    result.green = green;
    result.blue = blue;
    result.opacity = 255;
    return result;
}

color defineColorWithOpacity (int8b red, int8b green, int8b blue, int8b opacity)
{
    color result;
    result.red = red;
    result.green = green;
    result.blue = blue;
    result.opacity = opacity;
    return result;
}