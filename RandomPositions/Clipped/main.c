/**
* @file         main.c
* @brief        main function
* @detail       Main file of Conway's Game Of Life project
* @include      func.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include "func.h"

/**
* @fn main
* @brief generating tables and creating the game due to random 7 type of position which the user select
*/
int main(){
// unsigned char copy[width * heigh];
//unsigned char pixels[width * heigh * 4];
    capacity = 0;
    char start;
	srand(time(NULL));

/**
* @brief       Taking the capacity 
* @warning     Only range of [1;7] acceptable, otherwise it'll ask again untill get the integer in that range
*/	
	printf("Please, choose the starting capacity level in [1; 7] range:\n");
	char buffer[80] = "";
	for(int i=0; i<7; i++){
		fgets(buffer, sizeof(buffer), stdin);
		if (sscanf(buffer, "%d", &capacity) != 1) {
			capacity = 0;
		}
		if (capacity >= 1 && capacity <= 7) {
			break;
		}
		printf("Please, choose the starting capacity level in [1; 7] range:\n");
	}
	
/**
*@brief Generates new table
*/
	generate();

/**
*@warning draft SDL
*/
// SDL_Init(SDL_INIT_VIDEO);
// SDL_Window *window = SDL_CreateWindow("life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, heigh, SDL_WINDOW_SHOWN);
// SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
// SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, width, heigh);
// SDL_Event event;
// while (1) {
//     if (SDL_PollEvent(&event)) {
//       if (event.type == SDL_QUIT) {
//         break;
//       }
//     }

/**
*@brief Displays the datas in the t and t+1 tables separately 
*/
    display(table_t); 
    printf("\n\n Type '1' to play the game.\n Type '0' to exit.\n");
	// printf("\033[2J");
	int turn = 0;
	int generation;
	scanf("\n%c", &start);
    if (start == '1'){
		for(generation = 0; generation < 150; generation++) {
			usleep(30000);
			// printf("\033[2J");
			if (turn == 0){
                                for (int j = 0; j < heigh; j++){
		            for (int i = 0; i < width; i++){
		            	rules(i, j, table_t, table_N);
		            }
                }
				display(table_N);
				turn = 1;

			} else if (turn == 1){
                for (int j = 0; j < heigh; j++){
		            for (int i = 0; i < width; i++){
		            	rules(i, j, table_N, table_t);
		            }
                }
				display(table_t);
				turn = 0;
			}
			usleep(30000);
            printf("\033[r;cH");
            
		}
    }

/**
*@warning draft SDL
*/
  //   SDL_UpdateTexture(texture, NULL, pixels, width * 16);
  //   SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  //   SDL_RenderClear(renderer);
  //   SDL_RenderCopy(renderer, texture, NULL, NULL);
  //   SDL_RenderPresent(renderer);
  //   SDL_Delay(5);
  // }
  // SDL_DestroyTexture(texture);
  // SDL_DestroyRenderer(renderer);
  // SDL_DestroyWindow(window);
  // SDL_Quit();
  // return 0;
 /**
 *@warning for compiling with SDL: gcc game.c main.c `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttfgcc game.c main.c `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
  */

}
