#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>



//#include "cut.h"
#define MAX 5
int getTop(int i,int j,int arr[MAX][MAX]);
int getBottom(int i,int j,int arr[MAX][MAX]);
int getRight(int i,int j,int arr[MAX][MAX]);
int getLeft(int i,int j,int arr[MAX][MAX]);
int getLeftTop(int i,int j,int arr[MAX][MAX]);
int getRightTop(int i,int j,int arr[MAX][MAX]);
int getLeftBottom(int i,int j,int arr[MAX][MAX]);
int getRightBottom(int i,int j,int arr[MAX][MAX]);
bool decide_mode(int i, int j, int array[MAX][MAX]);
#endif
