#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//#define DEBUG
#ifdef DEBUG
#define LOG(msg) printf("%s\n", msg)
#else
#define LOG(msg)
#endif // DEBUG
#include "settings.h"



void Reset(Game *game);
void Load(Game *game, FILE *save);
void Malloc(Game *game);
void Free(Game *game);
void Save(Game *game, FILE *save);
void Step(Game *game, Cell cell);

#endif // GAME_H_INCLUDED
