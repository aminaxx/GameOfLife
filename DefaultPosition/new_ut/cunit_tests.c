#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/CUnit.h>
#define MAX 5
//#include "header.h"



static const double epsilon=0.000000001;
 int array[MAX][MAX] = {
                        {0,0,1,0,0},
                        {0,0,1,0,0},
                        {0,1,1,1,0},
                        {0,0,1,0,0},
                        {0,0,0,0,0},
                    };
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

//for checking if circular table is working well or no chech some of critical points
void test_point_location(void){

	CU_ASSERT_DOUBLE_EQUAL(getTop(2,1,array),0,epsilon);

	CU_ASSERT_DOUBLE_EQUAL(getTop(1,2,array),1,epsilon);

	CU_ASSERT_DOUBLE_EQUAL(getBottom(2,1,array),0,epsilon);

	CU_ASSERT_DOUBLE_EQUAL(getLeft(1,1,array),0,epsilon);

        CU_ASSERT_DOUBLE_EQUAL(getLeft(1,4,array),0,epsilon);//it mustn't give error bc the
         //left of the most left value is most right one

    CU_ASSERT_DOUBLE_EQUAL(getTop(0,2,array),0,epsilon);

    CU_ASSERT_DOUBLE_EQUAL(getLeft(3,0,array),0,epsilon);//left of the most left must return to right

CU_ASSERT_DOUBLE_EQUAL(getBottom(4,2,array),1,epsilon);



}

int main() {
  if(CUE_SUCCESS !=CU_initialize_registry())
        return CU_get_error();

    CU_pSuite pS1=CU_add_suite("Testing points",NULL,NULL);

    CU_ADD_TEST(pS1,test_point_location);

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_basic_run_tests();
    return 0;
 }



