#include <header.h>

#include <stdbool.h>

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
             arr[i][j] = array[i][j];//fill new array with values of array to use it in future
             
             int c = (arr[i][j] != 0) ? 100 : 40 ;//defining color depending on value
		
			printf("\033[%dm  ",c);
                          



         }
                                   

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
                 {
                 	
                 		printf("\033[2J");

                    isChanged = true;
                    for (int i = 0; i < MAX; ++i)
                    {
                         for (int j = 0; j < MAX; ++j)

                         {

                            
                             int c = (arr[i][j] != 0) ? 100 : 40 ;// deciding the colors of cells during motion
		
			                 printf("\033[%dm  ",c);
                         }

                        printf("\n");
                    }
                     printf("\n");
                    
                     sleep (1);
                 }
            }
        }
    }
    
  
    

    return 0;
 }

