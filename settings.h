#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

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

typedef enum Player
{
    none,
    white,
    black
}Player;

typedef struct Cell
{
    Player owner;
    int x, y;

}Cell;

typedef struct Game
{
    int size;
    int x;
    int y;
    Cell **board; //0nal ures a mezo, 1nel fekete, -1nel feher
    Player nextPlayer;
}Game;

int GetColumn(Game *game);
int GetRow(Game *game);


#endif // SETTINGS_H_INCLUDED
