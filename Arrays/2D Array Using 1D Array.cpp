#include <stdio.h>

/*
Lets analyze a 2D array of dimention 4x4 
Note: row starts from 0, column starts from 0

2D Array's Index -> 1D Array's Index -> Scanned  Pattern for Index
 00 01 02 03     ->  0   1   2   3   ->  4*0+0 4*0+1 4*0+2 4*0+3    column*current_row + current_column
 10 11 12 13     ->  4   5   6   7   ->  4*0+0 4*0+1 4*0+2 4*0+3    column*current_row + current_column
 20 21 22 23     ->  8   9  10  11   ->  4*0+0 4*0+1 4*0+2 4*0+3    column*current_row + current_column
 30 31 32 33     ->  12 13  14  15   ->  4*0+0 4*0+1 4*0+2 4*0+3    column*current_row + current_column
*/


/**
 * @brief This function is supposed to convert the 2D array's index to a 1D array index.
 * 
 * When a function is called, the caller's execution is paused, and a new stack frame is created for the callee function.
 * When the callee finishes its execution, the caller's execution is resumed.
 * But since we need to call the function a lot of times to get the index, it will cause a performance issue.
 * Inlining this function will tell the compiler to replace its call with its code wherever this function is called.
 * In other words, inserting function code at the addresses of each function call.
 * 
 * @param i Current row
 * @param j Current column
 * @return int The 2D array's equivalent index for 1D array.
 */
inline int ToOneDimentionaArrayIndex(int i, int j, int column){
    return column*i + j;
}


int main(){

    
    /**
     * @brief Declare & initiate the row, column & size for desired 2D array.
     */
    const int    row    = 4,  col = 3;
    const size_t size   = row*col;

    /**
     * @brief Creating 1D array but storing elements in row/column style, so that it looks like a 2D array.
     */
    int array[size]     = {  10,   15,   20,
                             25,   30,   35,
                             40,   45,   50,
                             55,   60,   65
                            };



    for( int i = 0; i < row; i++ ){
        for ( int j = 0; j < col; j++ ){
            /**
             * @brief The 2D array is actually implemented by 1D array.
             * So, must use a single subscipt operator insted of double subscript operator.
             * Therefore, we need to convert the 2D array's index to an 1D array index;
             */
            printf("%d  ", array[ToOneDimentionaArrayIndex(i,j,col)]   );
        }
        printf("\n");
    }

    int i, j;
    printf("\nLets, set -5 at index (i,j) of array.");
    printf("\nEnter the value of i & j: ");
    scanf("%d %d", &i, &j);
    array[ToOneDimentionaArrayIndex(i,j,col)] = -5;
    printf("Element at array[%d][%d] changed to -5\n\n", i, j);

    for( int i = 0; i < row; i++ ){
        for ( int j = 0; j < col; j++ ){
            printf("%d  ", array[ToOneDimentionaArrayIndex(i,j,col)]   );
        }
        printf("\n");
    }
  

    return 0;
}



 
