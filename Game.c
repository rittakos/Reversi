#include "draw.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include <stdlib.h>
#include "settings.h"


void CreateGame(Game *game)
{
    (*game).board = (Cell**)malloc((*game).size * sizeof(Cell*));

    for (int idx = 0; idx < (*game).size; ++idx)
    {
        (*game).board[idx] = (Cell*)malloc((*game).size * sizeof(Cell));
    }
}


void FreeGame(Game *game)
{

    for (int idx = 0; idx < (*game).size; ++idx)
    {
        free((*game).board[idx]);
    }

    free((*game).board);
}

void Load(Game *game, FILE *save)
{

}

void Reset(Game *game)
{
    (*game).nextPlayer = white;
    for(int idy = 0; idy < GetRow(game); ++idy)
    {
        for(int idx = 0; idx < GetColumn(game); ++idx)
        {

            (*game).board[idx][idy].owner = none;
            (*game).board[idx][idy].x = idx;
            (*game).board[idx][idy].y = idy;
        }
    }
    (*game).board[GetColumn(game)/2 - 1][GetRow(game)/2 - 1].owner = white;
    (*game).board[GetColumn(game)/2][GetRow(game)/2 - 1].owner = black;
    (*game).board[GetColumn(game)/2 - 1][GetRow(game)/2].owner = black;
    (*game).board[GetColumn(game)/2][GetRow(game)/2].owner = white;
}

void Save(Game *game, FILE *save)
{

}

bool End(Game *game)
{
    bool whiteEnd = false;
    bool blackEnd = false;
    for(int idy = 0; idy < GetRow(game); ++idy)
    {
        for(int idx = 0; idx < GetColumn(game); ++idx)
        {
            if((*game).board[idy][idx].owner == none)
                return false;
            else if((*game).board[idy][idx].owner == black)
            {
                blackEnd = true;
                if(whiteEnd)
                    return false;
            }else
            {
                whiteEnd = true;
                if(blackEnd)
                    return false;
            }
        }
    }
    return true;
}


bool InMatrix(Game *game, Cell cell)
{
    if(cell.x < 0 || cell.x >= GetColumn(game))
        return false;
    if(cell.y < 0 || cell.y >= GetRow(game))
        return false;
    return true;
}

bool Turn(Game *game, Cell cell, int xDir, int yDir)
{
    Cell currentCell = (*game).board[cell.x][cell.y];
    if(cell.y == 0 || cell.x == 0)
        return false;
    if(cell.y == GetRow(game) - 1 || cell.x == GetColumn(game) - 1)
        return false;

    if((*game).board[cell.x + xDir][cell.y + yDir].owner ==(*game).nextPlayer)
        return false;

    do
    {
        currentCell.y += yDir;
        currentCell.x += xDir;
        currentCell = (*game).board[currentCell.x][currentCell.y];
        //printf("%d %d %d\n", currentCell.x, currentCell.y, currentCell.owner);
    }while(currentCell.owner != (*game).nextPlayer && InMatrix(game, currentCell) &&
            currentCell.owner != none);

    if(currentCell.owner != none)
    {
        do
        {
            currentCell.y -= yDir;
            currentCell.x -= xDir;
            (*game).board[currentCell.x][currentCell.y].owner = (*game).nextPlayer;
        }while(currentCell.x != cell.x && currentCell.y != cell.y);
        currentCell.y -= yDir;
        currentCell.x -= xDir;
        (*game).board[currentCell.x][currentCell.y].owner = (*game).nextPlayer;
        return true;
    }
    return false;
}

bool AllTurns(Game *game, Cell cell)
{
    bool succes = false;

    for(int x = -1; x <= 1; ++x)
    {
        for(int y = -1; y <= 1; ++y)
        {
            if(x != 0 || y != 0)
            {
                if(Turn(game, cell, x, y))
                    succes = true;
            }
        }
    }
    /*for(int id = -1; id <= 1; ++id)
    {
        if(id != 0)
        {
            if(Turn(game, cell, 0, id))
                succes = true;
            if(Turn(game, cell, id, 0))
                succes = true;
        }
    }*/

    return succes;
}

bool PossibleStep(Game *game, Cell cell)
{
    if(cell.owner == none && !End(game))
    {
        if(AllTurns(game, cell))
            return true;
    }
    return false;
}


void Step(Game *game, Cell cell)
{
    if(PossibleStep(game, cell))
    {

        cell.owner = (*game).nextPlayer;
        if((*game).nextPlayer == black)
        {
            (*game).nextPlayer = white;
        }

        else
        {
            (*game).nextPlayer = black;
        }
        //AllTurns(game, cell);
    }
}



