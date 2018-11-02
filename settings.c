#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "settings.h"


int GetColumn(Game *game)
{
    return (*game).size;
}
int GetRow(Game *game)
{
    return (*game).size;
}
