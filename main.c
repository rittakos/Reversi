#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include <stdlib.h>
#include "draw.h"
#include "game.h"
#include <stdio.h>
#include <stdbool.h>




void Play()
{

}


int main(int argc, char *argv[]) {

    LOG ("askdjflasdjfklj");
    FILE *save = fopen("save.txt", "wt");
    Game game;
    game.size = 8;
    bool reset = false;


    CreateGame(&game);
    Load(&game, &save);
    if(reset)
        Reset(&game);
    Play(&game);

    Reset(&game);
    Cell cell;
    while(!End(&game))
    {
        printf("next: %d\n", game.nextPlayer);
        for(int idy = 0; idy < game.size; ++idy)
        {
            for(int idx = 0; idx < game.size; ++idx)
            {
                printf("%d ", game.board[idx][idy].owner);
            }
            printf("\n");
        }
        scanf("%d %d", &cell.x, &cell.y);
        Step(&game, game.board[cell.x][cell.y]);
        printf("\n");

    }



    fclose(save);
    Load(&game, save);
    //board.board = malloc()
    /* ablak létrehozása */
    SDL_Window *window;
    SDL_Renderer *renderer;
    sdl_init("Reversi", 440, 360, &window, &renderer);

    //DrawBoard(board.size, &renderer);
    //GameMode1(board);//ember vs emeber
    //GameMOde2(board);//ember vs gep

    DrawBoard(renderer, game);

    DrawCircle(renderer, 100, 100, 75);


    SDL_RenderPresent(renderer);

    /* varunk a kilepesre */
    SDL_Event ev;
    while (SDL_WaitEvent(&ev) && ev.type != SDL_QUIT) {
    }

    /* ablak bezarasa */
    SDL_Quit();

    FreeGame(&game);

    return 0;
}
