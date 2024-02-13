#include "my_mat.h"
#include <stdio.h>
#include <stdbool.h>
#define ROWS 2
#define COLS 2

int fillMatrix(int matrix[ROWS][COLS]){
    for(size_t i=0; i<ROWS; i++){
        for(size_t j=0; j<COLS; j++){
            printf("enter the value for row %lu col %lu : ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    return 0;
}

int isValidPath(int matrix[ROWS][COLS],int i,int j,bool ok){
    if(ok){
        if(matrix[i][j]==0){
        printf("FALSE\n");
        return 0;
    }
    printf("TRUE\n");
    return 1;
    }
    else{
        if(matrix[i][j]==0){
        return 0;
        }
    
        return 1;
    }
}

int findShortestPath(int matrix[ROWS][COLS], int i, int j) {
    int distMatrix[ROWS][COLS];

    if (isValidPath(matrix, i, j,false) == 0) {
        return 0;
    }

    // Copy the original matrix to distMatrix
    for (size_t x = 0; x < ROWS; x++) {
        for (size_t y = 0; y < COLS; y++) {
            distMatrix[x][y] = matrix[x][y];
        }
    }

    // Floyd-Warshall algorithm for finding shortest paths
    for (size_t k = 0; k < ROWS; k++) {
        for (size_t a = 0; a < ROWS; a++) {
            for (size_t b = 0; b < COLS; b++) {
                if (distMatrix[a][b] > distMatrix[a][k] + distMatrix[k][b]) {
                    distMatrix[a][b] = distMatrix[a][k] + distMatrix[k][b];
                }
            }
        }
    }

    printf("%d\n", distMatrix[i][j]); // Add a newline character
    return distMatrix[i][j];
}