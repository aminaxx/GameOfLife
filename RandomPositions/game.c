#include "func.h"

void generate(){ // Generates the table based on the selected capacity level
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

void display(char world[width][heigh]){ //Prints the next world on screen

	for (int j = 0; j < heigh; j++){
		for(int i = 0 ;i < width; i++){
			printf("\033[31m%c", world[i][j]);                   //isleyen part, asagidakilar draftdi, bax gor neyniyirsen <3
		}
		printf("\n");
	}

    
		
	// // printf("\033[2J");
	// // printf("\033[?25l");
    // for (int j = 0; j < heigh; j++){
    //     printf("\033[4H");
	// 	for(int i = 0 ;i < width; i++){
	// 		int c = (world[i][j] != 0) ? 40 : 104 ;
    //         printf("\033[%dm  ",c);
	// 	}
	// 	printf("\n");
	// }
	// int s,si;


// // for(s=0;s<heigh;s++){
// // 	printf("\033[%d;4H",s+2);
// // 	for(si=0;si<width;si++){
		
// // 		//struct cell temp=C_new(s,si);
// // 		//arr[s][si]=temp;
// // 		//printf("0or 1");
// // 		//scanf("%d",&(temp.mode));
// // 		// int c = (world[s][si] != 0) ? 40 : 104 ;
// //         int c = (world[s][si]);
// // 		//int c =  ? 40 : 104;
// // 			printf("\033[%dm  ",c);
// // }	
// // }


}

void rules(int b, int c, char table1[width][heigh], char tableN[width][heigh]){ // Checks how many living neighbors this tile currently has.
	int neighbors = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if ((i == 0 && j == 0) || b + i >= width || b + i < 0 || c + j >= heigh	|| c + j < 0) { //either in current cell or neightb.
				continue;	
			}

			if (table1[b + i][c + j] == '0'){ //if cell is alive
                neighbors++;
            }
		} 
	}
	
//due to the rules
	if (neighbors == 3 || (neighbors == 2 && table1[b][c] == '0')) { //Any live cell with two or three live neighbors survives.
		tableN[b][c] = '0';
	} else {
		tableN[b][c] = ' ';
	}

    // if (neighbors == 3 || table1[b][c] == ' ') {//Any dead cell with three live neighbors becomes a live cell.
	// 	tableN[b][c] = '0';
	// } else {
	// 	tableN[b][c] = ' ';
	// }
}