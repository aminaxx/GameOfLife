#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include "func.h"

int main(){
	unsigned char copy[width * heigh];
  	unsigned char pixels[width * heigh * 4];
    capacity = 0;
    char start;
	srand(time(NULL));
	
	printf("Please, choose the starting capacity level in [1; 7] range:\n");
	char buffer[80] = "";
	
	for(int i=0; i<7; i++){ //taking the capacity
		fgets(buffer, sizeof(buffer), stdin);
		if (sscanf(buffer, "%d", &capacity) != 1) {
			capacity = 0;
		}
		if (capacity >= 1 && capacity <= 7) {
			break;
		}
		printf("Please, choose the starting capacity level in [1; 7] range:\n");
	}
	
	generate(); //generates new table

SDL_Init(SDL_INIT_VIDEO);
SDL_Window *window = SDL_CreateWindow("life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, heigh, SDL_WINDOW_SHOWN);
SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, width, heigh);
SDL_Event event;
while (1) {
    if (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        break;
      }
    }
    display(table_t); //displays the datas
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

    SDL_UpdateTexture(texture, NULL, pixels, width * 4);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(5);
  }
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;

}