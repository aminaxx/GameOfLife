#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define heigh 30 //row
#define width 80 //col
int capacity;
char table_t[width][heigh], table_N[width][heigh]; //table t and t+1

void generate(); // Generates the table based on the selected capacity level
void display(char world[width][heigh]); //Prints the next world on screen
void rules(int b, int c, char table1[width][heigh], char tableN[width][heigh]); // Checks how many living neighbors this tile currently has.

#endif