#include "my_mat.h"
#include "my_mat.c"
#include <stdio.h>
#include <stdbool.h>
#define ROWS 2
#define COLS 2
 
int main(){
    int matrix[ROWS][COLS];
    printf("enter a char :");
    int userInput = getchar();
    while(userInput!='D'){
        switch(userInput){
            case 'A':
                fillMatrix(matrix);
                break;

            case 'B':
                int i,j;
                printf("enter i value :");
                scanf("%d",&i);
                printf("enter j value :");
                scanf("%d",&j);
                isValidPath(matrix,i,j,true);
                break;
            
            case 'C':
                int a,b;
                printf("enter i value :");
                scanf("%d",&a);
                printf("enter j value :");
                scanf("%d",&b);
                findShortestPath(matrix,a,b);
                break;
            
            case 'D':
            case EOF:
                return 0;

            default :
                //printf("please enter one of those chars (A,B,C,D,EOF)\n");
                break;         
        }
        getchar();
        printf("enter a char :");
        userInput = getchar();
    }

    return 0;
}