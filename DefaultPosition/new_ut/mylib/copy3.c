#include "header.h"
//#include "cut.h"
// in all functions if statement for critical cells that are close to the bound
int getTop(int i,int j,int arr[MAX][MAX]){//for reaching up of given coordinate
   
    int y;
    if(i == 0) 
    {
        y = arr[MAX-1][j];
    }
    else
    {
        y = arr[i-1][j];
    }

    return y;

}
int getBottom(int i,int j,int arr[MAX][MAX]){//for reaching down of given coordinate
  
    int y;
    if(i == MAX - 1)
    {
        y = arr[0][j];
    }
    else
    {
        y = arr[i+1][j];
    }
    
    return y;

}


int getRight(int i,int j,int arr[MAX][MAX]){//for reaching right of given coordinate
    
    int y;
    if(j == MAX - 1)
    {
        y = arr[i][0];
    }
    else
    {
        y = arr[i][j+1];
    }

    return y;

}
int getLeft(int i,int j,int arr[MAX][MAX]){//for reaching left of given coordinate

    int y;
    if(j == 0)
    {
        y = arr[i][MAX - 1];
    }
    else
    {
        y = arr[i][j-1];
    }
    
    return y;

}


int getLeftTop(int i,int j,int arr[MAX][MAX]){//for reaching left top of given coordinate
    
    int y;
    if(i == 0 && j != 0)
    {
        y = arr[MAX-1][j-1];
    }
    else if(i != 0 && j == 0)
    {
        y = arr[i-1][MAX-1];
    }
    else if(i == 0 && j == 0)
    {
        y = arr[MAX-1][MAX-1];
    }
    else
    {
        y = arr[i-1][j-1];
    }
    
    return y;

}
int getRightTop(int i,int j,int arr[MAX][MAX]){//for reaching right top of given coordinate
 
    int y;
    if(i == 0 && j != MAX - 1)
    {
        y = arr[MAX-1][j+1];
    }
    else if(i != 0 && j == MAX - 1)
    {
        y = arr[i-1][0];
    }
    else if(i == 0 && j == MAX - 1)
    {
        y = arr[MAX-1][0];
    }
    else
    {
        y = arr[i-1][j+1];
    }
    
    return y;
}
int getLeftBottom(int i,int j,int arr[MAX][MAX]){ //for reaching left top of given coordinate

    int y;
    if(i == MAX - 1 && j != 0)
    {
        y = arr[0][j-1];
    }
    else if(i != MAX - 1 && j == 0)
    {
        y = arr[i+1][MAX-1];
    }
    else if(i == MAX - 1 && j == 0)
    {
        y = arr[0][MAX-1];
    }
    else
    {
        y = arr[i+1][j-1];
    }
    
    return y;
}

int getRightBottom(int i,int j,int arr[MAX][MAX]){//for reaching right bottom of given coordinate
   
    int y;
    if(i == MAX - 1 && j != MAX - 1)
    {
        y = arr[0][j+1];
    }
    else if(i != MAX - 1 && j == MAX - 1)
    {
        y = arr[i+1][0];
    }
    else if(i == MAX - 1 && j == MAX - 1)
    {
        y = arr[0][0];
    }
    else
    {
        y = arr[i+1][j+1];
    }

    return y;

}

bool decide_mode(int i, int j, int array[MAX][MAX])  
//for deciding is given cell with coordinates
// i j died or live it depend on given counter as rule
{
    int counter = 0;
    
    // ------------ //
    
    int top = getTop(i, j, array);
    counter = counter + top;

    int bottom = getBottom(i, j, array);
    counter = counter + bottom;
    
    int left = getLeft( i, j, array);
    counter = counter + left;
    
    int right = getRight(i, j, array);
    counter = counter + right;
    
    // ------------ //

    int ltop = getLeftTop(i, j, array);
    counter = counter + ltop;

    int rtop = getRightTop(i, j, array);
    counter = counter + rtop;

    int lbottom = getLeftBottom(i, j, array);
    counter = counter + lbottom;

    int rbottom = getRightBottom(i, j, array);
    counter = counter + rbottom;
    
    // ------------ //
    

    if(array[i][j] == 0)
    {
        if(counter == 3)
        {
            //printf("%d %d --- ", i, j);
            //printf("live \n");
            array[i][j] = 1;
            return true;
        }
    }
    else if(array[i][j] == 1)
    {
        if(counter != 2 && counter != 3)
        {
            //printf("%d %d --- ", i, j);
            //printf("dead \n");
            array[i][j] = 0;
            return true;
        }
    }
    
    return false;
}

















