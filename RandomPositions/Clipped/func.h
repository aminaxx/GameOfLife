#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include <SDL2/SDL.h> // for initializing and sutdown functions 
#include <SDL2/SDL_image.h> // for rendering images and graphics on screen 
#include <SDL2/SDL_timer.h> // for using SDL_Delay() functions 

// const int SCREEN_WIDTH = 640;
// const int SCREEN_HEIGHT = 480;
 

#define heigh 30 //row
#define width 80 //col
int capacity;
char table_t[width][heigh], table_N[width][heigh]; //table t and t+1

void generate(); // Generates the table based on the selected capacity level
void display(char world[width][heigh]); //Prints the next world on screen
void rules(int b, int c, char table1[width][heigh], char tableN[width][heigh]); // Checks how many living neighbors this tile currently has.

#endif

// all: main.o game.o 
// 	gcc -o run main.o game.o
// ran:
// 	./run
// main.o: main.c
// 	gcc main.c
// game.o: copy3.c
// 	gcc game.c
// clean:
// 	rm run

// mkdir build
// cd build
// cmake ..
// make
// ./GameOfLife