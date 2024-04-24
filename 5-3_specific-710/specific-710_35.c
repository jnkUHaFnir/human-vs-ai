#include <stdio.h>
#include <stdlib.h>

void findx(int x, int a, int tab[][3], int **result, int *k);
void print_result(int **result, int k);

int main() {
    int a;
    scanf("%d", &a); // Number of puzzles
    int tab[a][3];

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &tab[i][j]); // Input puzzles
        }
    }

    int **result = malloc(a * sizeof(int*)); // Allocate memory for result
    for (int i = 0; i < a; i++) {
        result[i] = malloc(3 * sizeof(int));
    }

    int k = 0;
    findx(0, a, tab, result, &k);
    
    if (k == 0) {
        printf("no result\n");
    }

    for (int i = 0; i < a; i++) {
        free(result[i]); // Free memory allocated for result
    }
    free(result);
    
    return 0;
}

void findx(int x, int a, int tab[][3], int **result, int *k) {
    for (int i = 0; i < a; i++) {
        if (tab[i][0] == x) {
            if (tab[i][2] == 0) {
                for (int m = 0; m < 3; m++) {
                    result[*k][m] = tab[i][m];
                }
                (*k)++;
                print_result(result, *k);
                return;
            } else {
                for (int m = 0; m < 3; m++) {
                    result[*k][m] = tab[i][m];
                }
                (*k)++;
                findx(tab[i][2], a, tab, result, k);
            }
        }
    }
}

void print_result(int **result, int k) {
    printf("%d\n", k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
