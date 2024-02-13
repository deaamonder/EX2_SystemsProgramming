#include <stdio.h>
#include <stdbool.h>
#define ROWS 2
#define COLS 2

int fillMatrix(int matrix[ROWS][COLS]);

int findShortestPath(int matrix[ROWS][COLS],int i,int j);

int isValidPath(int matrix[ROWS][COLS],int i, int j,bool ok);