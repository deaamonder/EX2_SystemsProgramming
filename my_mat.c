#include "my_mat.h"
#include <stdio.h>
#define ROWS 10
#define COLS 10

int matrix[ROWS][COLS];

int fillMatrix(int matrix[ROWS][COLS]){
    for(size_t i=0; i<10; i++){
        for(size_t j=0; j<10; j++){
            printf("enter the value for row %d col %d : ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    return 0;
}

int isValidPath(int i,int j){
    if(matrix[i][j]==NULL || matrix[i][j]==0){
        printf("FALSE");
        return 0;
    }
    printf("TRUE");
    return 1;
}

int findShortestPath(int i, int j){
    int distMatrix[10][10];
    if(isValidPath(i,j)==0){
        return 0;
    }
    for (size_t x = 0; x < 10; x++)
    {
        for (size_t y = 0; y < 10; y++)
        {
            distMatrix[x][y] = matrix[x][y];
        }
    }
    for (size_t k = 0;k < 10; k++)
    {
        for (size_t a = 0; a < 10; a++)
        {
            for (size_t b = 0; b < 10; b++)
            {
                if(distMatrix[a][b]>distMatrix[a][k]+distMatrix[k][b]){
                    distMatrix[a][b] = distMatrix[a][k]+distMatrix[k][b];
                }
            }
        }
    }
    return distMatrix[i][j];
}