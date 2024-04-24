#include <stdio.h>
#include <stdlib.h>

int findx(int x, int n, int tab[][3], int **result, int *k);

void print_result(int **result, int k) {
    printf("%d\n", k); // Print the count of puzzles
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a;
    scanf("%d", &a); // Read number of puzzles
    int tab[a][3]; // Array for puzzles

    // Dynamically allocate memory for the result array
    int **result = (int **)malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++) {
        result[i] = (int *)malloc(3 * sizeof(int));
    }

    int k = 0; // This will help track how many puzzles the result array has

    // Upload puzzles to array
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &tab[i][j]);
        }
    }

    if (!findx(0, a, tab, result, &k)) { // Start of recursion, because start has to be length 0
        printf("no result\n");
    } else {
        print_result(result, k);
    }

    // Free dynamically allocated memory
    for (int i = 0; i < a; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}

int findx(int x, int n, int tab[][3], int **result, int *k) {
    for (int i = 0; i < n; i++) {
        if (tab[i][0] == x) { // Look for puzzles with x length at start
            if (tab[i][2] == 0) { // If this is a puzzle with edge length zero at the end
                for (int m = 0; m < 3; m++) { // Add to result array
                    result[*k][m] = tab[i][m];
                }
                (*k)++;
                return 1;
            } else {
                result[*k][0] = tab[i][0];
                result[*k][1] = tab[i][1];
                result[*k][2] = tab[i][2];
                (*k)++;
                if (findx(tab[i][2], n, tab, result, k)) {
                    return 1;
                } else {
                    // Backtrack, this path didn't lead to a solution
                    (*k)--;
                }
            }
        }
    }
    return 0; // No result found
}
