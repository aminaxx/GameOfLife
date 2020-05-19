/**
* @file         game.c
* @brief        game
* @detail       Source code of Conway's Game Of Life
* @include      func.h
*/
#include "func.h"
#include <SDL2/SDL.h>

/**
* @fn     		generate
* @brief        Generates the table based on the selected capacity level
*/
void generate(){
    int life;
	for (int j=0;j<heigh;j++){
		for(int i=0;i<width;i++){
			life=(rand()%9);
			if (life<capacity) {
                table_t[i][j]='0';
            }
			else{ table_t[i][j]=' ';
            }
		}
	}
}

/**
* @fn 		   display
* @brief       Prints the next world(table) on screen
*/
void display(char world[width][heigh]){

	for (int j = 0; j < heigh; j++){
		for(int i = 0 ;i < width; i++){
			printf("\033[31m%c", world[i][j]);                  
		}
		printf("\n");
	}
}

void rules(int b, int c, char table1[width][heigh], char tableN[width][heigh]){ // Checks how many living neighbors this tile currently has.
	int neighbors = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if ((i == 0 && j == 0) || b + i >= width || b + i < 0 || c + j >= heigh	|| c + j < 0) { //either in current cell or neightb.
				continue;	
			}
/**       
*@brief     if cell is alive
*/
			if (table1[b + i][c + j] == '0'){
                neighbors++;
            }
		} 
	}
	
/**
* @brief       Due to the rules
*/
	if (neighbors == 3 || (neighbors == 2 && table1[b][c] == '0')) { //Any live cell with two or three live neighbors survives.
		tableN[b][c] = '0';
	} else {
		tableN[b][c] = ' ';
	}
/**
* @brief       Not generating properly with iy
*/	
 	//    if (neighbors == 3 || table1[b][c] == ' ') {//Any dead cell with three live neighbors becomes a live cell.
	// 	tableN[b][c] = '0';
	// } else {
	// 	tableN[b][c] = ' ';
	// }
}


/**
* @brief   SDL2
* @detail  I've tried to generate the game with sdl but got the error with cmake, thus commented to left the clear worked code
*/

// void renderGrid(int *grid, SDL_Renderer *renderer, SDL_Texture *aliveTexture,
//                 SDL_Texture *deadTexture) {
//   for (int r = 0; r < heigh; r++) {
//     for (int c = 0; c < width; c++) {
//       SDL_Rect quad = {c * CELL_SIZE, r * CELL_SIZE, CELL_SIZE, CELL_SIZE};
//       SDL_RenderCopy(renderer,
//                      grid[r * COLUMNS + c] ? aliveTexture : deadTexture, NULL,
//                      &quad);
//     }
//   }
// }

// void clearGrid(int *grid) {
//   for (int i = 0; i < heigh * width; i++) {
//     grid[i] = 0;
//   }
// }
