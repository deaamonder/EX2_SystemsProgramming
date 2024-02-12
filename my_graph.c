#include "my_mat.h"
#include <stdio.h>
#define ROWS 10
#define COLS 10

int matrix[ROWS][COLS];

 
int main(){
    char userInput ;
    printf("enter a char :");
    scanf("%c",&userInput);
    if(userInput == 'A'){
        fillMatrix(matrix);
    }
    if(userInput == 'B'){
        int i,j;
        printf("enter i value :");
        scanf("%d",&i);
        printf("enter j value :");
        scanf("%d",&j);
        isValidPath(i,j);
    }
    if(userInput == 'C'){
        int a,b;
        printf("enter i value :");
        scanf("%d",&a);
        printf("enter j value :");
        scanf("%d",&b);
        findShortestPath(a,b);
    }
    if(userInput == 'D'){
        
    }
}