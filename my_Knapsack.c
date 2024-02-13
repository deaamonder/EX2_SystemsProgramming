#include <stdio.h>
#define MAX_ITEMS 5
#define MAX_WEIGHT 20

int knapSack(int weights[], int values[], int selected_bool[]) {
    int table[MAX_ITEMS + 1][MAX_WEIGHT + 1];

    for (int i = 0; i <= MAX_ITEMS; i++) {
        for (int w = 0; w <= MAX_WEIGHT; w++) {
            if (i == 0 || w == 0) {
                table[i][w] = 0;
            } else {
                if (weights[i-1] > w) {
                    table[i][w] = table[i-1][w];
                } else {
                    if(table[i-1][w] > table[i-1][w-weights[i-1]] + values[i-1]){
                        table[i][w] = table[i-1][w];
                    }
                    else{
                        table[i][w] = (table[i-1][w-weights[i-1]] + values[i-1]);
                    }
                }

            }
        }
    }

    int result[MAX_ITEMS];
    int count = 0;
    int w = MAX_WEIGHT;

    for (int i = MAX_ITEMS; i > 0 && w > 0; i--) {
        if (table[i][w] != table[i-1][w]) {
            selected_bool[i-1] = 1;
            result[count++] = i;
            w -= weights[i-1];
        }
    }

    return table[MAX_ITEMS][MAX_WEIGHT];
}

int main() {
    int weights[MAX_ITEMS], values[MAX_ITEMS], selected_bool[MAX_ITEMS] = {0};

    printf("Enter weights and values for 5 items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if(i==0){
            printf("Item a - Value: ");
            scanf("%d", &values[i]);
            printf("Item a - Weight: ");
            scanf("%d", &weights[i]);
        }
        if(i==1){
            printf("Item b - Value: ");
            scanf("%d", &values[i]);
            printf("Item b - Weight: ");
            scanf("%d", &weights[i]);
        }
        if(i==2){
            printf("Item c - Value: ");
            scanf("%d", &values[i]);
            printf("Item c - Weight: ");
            scanf("%d", &weights[i]);
        }
        if(i==3){
            printf("Item d - Value: ");
            scanf("%d", &values[i]);
            printf("Item d - Weight: ");
            scanf("%d", &weights[i]);
        }
        if(i==4){
            printf("Item e - Value: ");
            scanf("%d", &values[i]);
            printf("Item e - Weight: ");
            scanf("%d", &weights[i]);
        }
    }

    int maxValue = knapSack(weights, values, selected_bool);
    printf("\nMaximum profit: %d\n", maxValue);

    printf("\nItems that give the maximum profit: ");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (selected_bool[i]) {
            if(i==0){
                printf("a ");
            }
            if(i==1){
                printf("b ");
            }
            if(i==2){
                printf("c ");
            }
            if(i==3){
                printf("d ");
            }
            if(i==4){
                printf("e ");
            }   
        }
    }
    return 0;
}