#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include  <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <time.h>
#include <SDL.h>
#include <header.h>
#define MAX 5


//this program is not working correctly it shows initial state of table then doesnt change and stay same also happens displacement of grapics



int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr,"Problem can not init SDL2 \n");
		return 0;
	}

SDL_Window* window = SDL_CreateWindow("GAME OF LIFE",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,500, 500, SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	assert (renderer != NULL);
	//SDL_SetRenderDrawColor(renderer, 225, 255,225,225);
	//SDL_RenderClear(renderer);

	//SDL_SetRenderDrawColor(renderer, 0,0,0,0);
	int array[MAX][MAX] = {
                        {0,0,1,0,0},
                        {0,0,1,0,0},
                        {0,1,1,1,0},
                        {0,0,1,0,0},
                        {0,0,0,0,0},
                    };
    
    int arr[MAX][MAX];
    for (int i = 0; i <= MAX; ++i)
    {
    	   //  SDL_RenderDrawLine(renderer, 
            
        //         0, 30*i,          /* x1, y1 */
        //         200, 30*i /* x2, y2 */
        // );
         for (int j = 0; j <= MAX; ++j)
         {
             arr[i][j] = array[i][j];
             
             if (arr[i][j] != 0) {
             	SDL_SetRenderDrawColor(renderer, 200,0,255,0);//giraginin rengi sirenevi kimi olan
             		//sleep(3);

              	//SDL_RenderDrawPoint(renderer,j,i); 
		 }
		// 	//printf("\033[%dm  ",c);
           SDL_RenderDrawLine(renderer,                 
                25*i, 1,           /* x1, y1 */                
                25*i, 180 /* x2, y2 *///alinan aradaki line larin uzunnugu
        );
               SDL_RenderDrawLine(renderer, 
            
                1, 25*i,          /* x1, y1 */
                180, 25*i /* x2, y2 */
        );
                          



         }
                                

        printf("\n"); 
    }
     SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);

    /* Render the game of life */
    for( int x=0; x<5; x++ ) {
        for( int y=0; y<5; y++) {
            if(array[y][x] == 1 ) {
                SDL_Rect r = {
                    x*18, /*   x    *///celler ust uste dushub gisalmasin deye
                    y*18, /*   y    */
                    25,   /* width  *///rengli cellerin galinligi
                    25   /* height */
                };
                SDL_RenderFillRect(renderer, &r);
            }
        }
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
                 		//printf("\033[2J");

                    isChanged = true;
                    for (int i = 0; i < MAX; ++i)
                    {
                         for (int j = 0; j < MAX; ++j)

                         {
                            //SDL_RenderClear(renderer);//novoe
                    if (arr[i][j] != 0) {


                SDL_SetRenderDrawColor(renderer, 255,0,255,0);

                                 //SDL_RenderPresent(renderer);  

                             //int c = (arr[i][j] != 0) ? 100 : 40 ;
		
			                 //printf("\033[%dm  ",c);
            }
            else {
              SDL_SetRenderDrawColor(renderer, 225, 255,225,225);  
            }
                            //SDL_RenderFillRect(renderer, &r);

                     }

                        printf("\n");
                    }
                     printf("\n");
                 
                     sleep (1);
                 }
            }
        }
    }
    ////////////////////////////////////////////////// new part
	// if (SDL_Init(SDL_INIT_VIDEO) != 0)
	// {
	// 	fprintf(stderr,"Problem can not init SDL2 \n");
	// 	return 0;
	// }

	// SDL_Window* window = SDL_CreateWindow("Life",
	// 									  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	// 									  1000, 1000, SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI);
	// SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	// assert (renderer != NULL);

// SIMPLE EVENT & DRAWING LOOP
	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		while (!quit && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			}
		}
		//draw(renderer);
		SDL_RenderPresent(renderer);
	}
	SDL_Quit();
	return 0;
}
