#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void findx(int x, int a, int tab[][3], int **result, int k);
void print_result(int **result, int k);

int main(){
    int a;
    scanf("%d", &a);

    int tab[a][3];
    int **result = (int **)malloc(a * sizeof(int *));

    for(int i = 0; i < a; i++){
        result[i] = (int *)malloc(3 * sizeof(int)); // Allocate memory for each puzzle
        for(int j = 0; j < 3; j++){
            scanf("%d", &tab[i][j]);
        }
    }

    int k = 0;
    findx(0, a, tab, result, k);

    for (int i = 0; i < a; i++) {
        free(result[i]); // Free memory for each puzzle
    }
    free(result); // Free memory for the array of puzzles

    return 0;
}

void findx(int x, int a, int tab[][3], int **result, int k){
    // Implementation of the findx function remains the same
}

void print_result(int **result, int k){
    printf("%d\n", k);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
