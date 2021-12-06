#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define ROWS 12
#define COLUMNS 4

void upDateSeats(int row, int col, int tab[row][col]);
void findEmptyRows(int rows, int cols, int matrix[rows][cols]);
void findFirstAvailableWindow(int rows, int cols, int matrix[rows][cols]);

int main(){

    
    int seats[ROWS][COLUMNS] = {{1,0,   0, 1},
                                {1,0,   0, 1},
                                {0,1,   0, 0},
                                {0,0,   1, 1},
                                {1,1,   0, 0},
                                {1,1,   0, 1},
                                {0,0,   1, 1},
                                {1,0,   0, 0},
                                {0,0,   1, 0},
                                {0,0,   0, 0},
                                {0,0,   0, 0},
                                {1,1,   0, 1}};

    upDateSeats(ROWS,COLUMNS,seats);
    findEmptyRows(ROWS, COLUMNS, seats);
    findFirstAvailableWindow(ROWS, COLUMNS, seats);

    return 0;
} 

/* Function for Testing. */
void upDateSeats(int rows, int cols, int tab[rows][cols]){
    int i,j;
    printf("Update Seats? (0/no):");
    if(!GetInteger()) return;
    for(i=0;i<rows;i++)
        for(j=0;j<cols;j++)
            tab[i][j] = (printf("seat (%2d,%2d)",i,j),GetInteger());
    printf("\n");
}


void findEmptyRows(int rows, int cols, int matrix[rows][cols]){
    
    for (int i; i < ROWS; i++){
        if ((matrix[i][0] == 0) && (matrix[i][1] == 0) && (matrix[i][2] == 0) && (matrix[i][3] == 0)){
            printf("Row: %d\n", i);
        }
    }
}

void findFirstAvailableWindow(int rows, int cols, int matrix[rows][cols]){
    int i = 0, j;
    int flag = 0;
    //for(int i = 0; i < rows; i++){
    while ((i < rows) && (flag == 0)){
      //for(int j = 0; j < cols; j++){
            j = 0;
            while ((j < cols) && (flag == 0)){
                //printf("M[%d][%d]: %d\n", i, j, matrix[i][j]);
                if ((matrix[i][j] == 0) && ((j == 0) || (j == 3))){
                    printf("First available window seat: %d,%d\n", i, j);
                    flag = 1;
            }
            j++;  
        }
        i++;
    }


}




