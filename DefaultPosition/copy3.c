
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
       #include <unistd.h>
#define MAX 5
//int arr[5][5]
int getTop(int i,int j,int arr[MAX][MAX]){
   
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
int getBottom(int i,int j,int arr[MAX][MAX]){
  
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
int getRight(int i,int j,int arr[MAX][MAX]){
    
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
int getLeft(int i,int j,int arr[MAX][MAX]){

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


int getLeftTop(int i,int j,int arr[MAX][MAX]){
    
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
int getRightTop(int i,int j,int arr[MAX][MAX]){
 
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
int getLeftBottom(int i,int j,int arr[MAX][MAX]){

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

int getRightBottom(int i,int j,int arr[MAX][MAX]){
   
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


int main()
{
    int array[MAX][MAX] = {
                        {0,0,1,0,0},
                        {0,0,1,0,0},
                        {0,1,1,1,0},
                        {0,0,1,0,0},
                        {0,0,0,0,0},
                    };
    
    int arr[MAX][MAX];
    for (int i = 0; i < MAX; ++i)
    {
         for (int j = 0; j < MAX; ++j)
         {
             arr[i][j] = array[i][j];
             //printf("%d - ", array[i][j]);
             int c = (arr[i][j] != 0) ? 100 : 40 ;
		//int c =  ? 40 : 104;
			printf("\033[%dm  ",c);
                          //printf("heyo");



         }
                                   //printf("heyo");

        printf("\n"); 
    }
    
    bool isChanged = true;

    while (isChanged)
    {
        isChanged = false;
        for(int i = 0; i < MAX; i++)
        {
            for(int j = 0; j < MAX; j++)
            {
                 if(decide_mode(i, j, arr))
                 {//clear
                 	//system("clear");
                 		printf("\033[2J");

                    isChanged = true;
                    for (int i = 0; i < MAX; ++i)
                    {
                         for (int j = 0; j < MAX; ++j)

                         {

                             //printf("%d - ", arr[i][j]);
                             int c = (arr[i][j] != 0) ? 100 : 40 ;
		
			                 printf("\033[%dm  ",c);
                         }

                        printf("\n");
                    }
                     printf("\n");//printf("\n");
                     ///usleep()
                     sleep (1);
                 }
            }
        }
    }
    
    // for (int i = 0; i < MAX; ++i)
    // {
    //      for (int j = 0; j < MAX; ++j)
    //      {
    //          printf("%d - ", arr[i][j]);
    //      }
    //     printf("\n");
    // }
    
    return 0;
 }













// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <time.h>
// #define MAX 5
// //int arr[5][5]
// int getTop(int i,int j,int arr[MAX][MAX]){
// 	//int arr[MAX][MAX];
// 	//int **arr=(int**)malloc(sizeof (int*));
// 	//int arr[MAX][MAX];
// 	//**arr=(int**)malloc(sizeof (int*));
// 	int y;
// 	y=arr[i-1][j];
// 	return y;

// }
// int getBottom(int i,int j,int arr[MAX][MAX]){
// 	//int arr[MAX][MAX];
// 	//int **arr=(int**)malloc(sizeof (int*));
// 	//int arr[MAX][MAX];
// 	//**arr=(int**)malloc(sizeof (int*));
// 	int y;
// 	y=arr[i+1][j];
// 	return y;

// }
// int getRight(int i,int j,int arr[MAX][MAX]){
// 	//int arr[MAX][MAX];
// 	//int **arr=(int**)malloc(sizeof (int*));
// 	//int arr[MAX][MAX];
// 	//**arr=(int**)malloc(sizeof (int*));
// 	int y;
// 	y=arr[i][j+1];
// 	return y;

// }
// int getLeft(int i,int j,int arr[MAX][MAX]){
// 	//int arr[MAX][MAX];
// 	//int **arr=(int**)malloc(sizeof (int*));
// 	//int arr[MAX][MAX];
// 	//**arr=(int**)malloc(sizeof (int*));
// 	int y;
// 	y=arr[i][j-1];
// 	return y;

// }


// int getLeftTop(int i,int j,int arr[MAX][MAX]){
// 	//int arr[MAX][MAX];
// 	//int **arr=(int**)malloc(sizeof (int*));
// 	//int arr[MAX][MAX];
// 	//**arr=(int**)malloc(sizeof (int*));
// 	int y;
// 	y=arr[i-1][j-1];
// 	return y;

// }
// int getRightTop(int i,int j,int arr[MAX][MAX]){
// 	//int arr[MAX][MAX];
// 	//int **arr=(int**)malloc(sizeof (int*));
// 	//int arr[MAX][MAX];
// 	//**arr=(int**)malloc(sizeof (int*));
// 	int y;
// 	y=arr[i-1][j+1];
// 	return y;

// }
// int getLeftBottom(int i,int j,int arr[MAX][MAX]){
// 	//int arr[MAX][MAX];
// 	//int **arr=(int**)malloc(sizeof (int*));
// 	//int arr[MAX][MAX];
// 	//**arr=(int**)malloc(sizeof (int*));
// 	int y;
// 	y=arr[i+1][j-1];
// 	return y;

// }
// int getRightBottom(int i,int j,int arr[MAX][MAX]){
// 	//int arr[MAX][MAX];
// 	//int **arr=(int**)malloc(sizeof (int*));
// 	//int arr[MAX][MAX];
// 	//**arr=(int**)malloc(sizeof (int*));
// 	int y;
// 	y=arr[i+1][j+1];
// 	return y;

// }

// int decide_mode(int array[][MAX])
// {
// 	int counter;
// 	//int **ar=(int**)malloc(MAX*sizeof(int*));

// 	for(int i=0;i<MAX;i++)
// 	{
// 		for(int j=0;j<MAX;j++)
// 		{ 
// 			counter=0;

// 			if(array[i][j]==0){
// 		int top= getTop(i,j,array);
// 		counter=counter+top;
// 		int bottom= getBottom(i, j,array);
// 		counter=counter+bottom;
// 		int left=getLeft( i, j, array);
// 		counter=counter+left;
// 		int right=getRightTop(i, j, array);
// 		counter=counter+right;

// 		int ltop= getLeftTop(i, j, array);
// 		counter=counter+ltop;

// 		int rtop=getRightTop( i,j,array);
// 		counter=counter+rtop;

// 		int lbottom=getLeftBottom( i, j, array);
// 		counter=counter+lbottom;

// 		int rbottom=getRightBottom( i, j, array);
// 		counter=counter+rbottom;


// if(counter==3){
// 	array[i][j]=1;
// 	printf("yepp");
// }
// else{
// 	array[i][j]=0;
// }
// //ar[i][j]=array[i][j];
// }

// //int** ar=(int**)malloc()
// return **array;
// }
// //return array[i][j];
// }
// //return
// //return **ar;

// }


// int main()
// {
// 	int array[MAX][MAX]={
// 						{0,0,1,0,0},
// 						{0,0,1,0,0},
// 						{0,1,1,1,0},
// 						{0,0,1,0,0},
// 						{0,0,0,0,0}
// 					};
// 	int  i;
// 	int s,si;
// 	int arr[MAX][MAX];
//     arr=(int**)malloc(sizeof (int*));

//     // for (int i = 0; i < MAX; ++i)
//     // {
//     // 	for (int j = 0; j < MAX; ++j)
//     // 	{
//     // 		arr[i][j] = array[o]i
//     // 	}
//     // }

// 	// i=getTop(3,2,array);
// 	// printf("%d",i);

// 	for(s=0;s<MAX;s++)
// 	{
// 		//printf("\033[%d;4H",s+2);

// 		for(si=0;si<MAX;si++)
// 		{
// 			arr[s][si]=array[s][si];
// 			int p = decide_mode( arr);
// 			printf("%d",p);
// 		//return 0;
// 		}
// 	}
// 	return 0;
// }

