#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "settings.h"

//#define DEBUG
#ifdef DEBUG
#define LOG(msg) printf("%s\n", msg)
#else
#define LOG(msg)
#endif // DEBUG


void sdl_init(char const *felirat, int szeles, int magas, SDL_Window **pwindow, SDL_Renderer **prenderer);
void DrawCircle(SDL_Renderer *renderer, int x, int y, int r);
void DrawBoard(SDL_Renderer *renderer, Game game);

#endif // DRAW_H_INCLUDED
