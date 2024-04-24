#include <stdio.h>
#include <stdlib.h>

int findx(int x, int a, int tab[][3], int **result, int k);
void print_result(int **result, int k);

int main() {
    int a;
    scanf("%d", &a);

    int tab[a][3];
    int **result = malloc(a * sizeof(int *)); // dynamically allocate memory for result
    for (int i = 0; i < a; i++) {
        result[i] = malloc(3 * sizeof(int));
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &tab[i][j]);
        }
    }

    findx(0, a, tab, result, 0);

    // Free dynamically allocated memory
    for (int i = 0; i < a; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}

int findx(int x, int a, int tab[][3], int **result, int k) {
    for (int i = 0; i < a; i++) {
        if (tab[i][0] == x) {
            if (tab[i][2] == 0) {
                for (int m = 0; m < 3; m++) {
                    result[k][m] = tab[i][m];
                }
                print_result(result, k);
                return 1; // Added return value to stop searching
            } else {
                for (int m = 0; m < 3; m++) {
                    result[k][m] = tab[i][m];
                }

                // Dynamically reallocate memory for result
                k++;
                int **new_result = realloc(result, (k + 1) * sizeof(int *));
                if (new_result == NULL) {
                    printf("Memory allocation failed");
                    exit(1);
                }
                result = new_result;

                if (findx(tab[i][2], a, tab, result, k)) {
                    return 1;
                }
            }
        }
    }
    return 0; // Return 0 if no result found
}

void print_result(int **result, int k) {
    printf("%d\n", k + 1);
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
