#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void findx(int x, int a, int tab[][3], int result[][3], int *k);
void print_result(int result[][3], int k);
bool add_puzzle_to_result(int result[][3], int puzzle[], int *k);

int main() {
    int a;
    scanf("%d", &a); // Here you get how many puzzles you have
    int tab[a][3]; // Array for puzzles
    int result[a][3]; // Result array, maximal possible number of puzzles
    int k = 0; // This will help me track how many puzzles my result array has

    for (int i = 0; i < a; i++) { // Upload puzzles to array
        for (int j = 0; j < 3; j++) {
            scanf("%d", &tab[i][j]);
        }
    }

    findx(0, a, tab, result, &k); // Start of recursion, because start has to be length 0

    if (k == 0) {
        printf("no result\n");
    }

    return 0;
}

void findx(int x, int a, int tab[][3], int result[][3], int *k) {
    for (int i = 0; i < a; i++) {
        if (tab[i][0] == x) { // Looking for puzzles with x length at start
            if (tab[i][2] == 0) { // If this is puzzle which ends rectangle
                add_puzzle_to_result(result, tab[i], k);
                print_result(result, *k);
                exit(0);
            } else {
                if (add_puzzle_to_result(result, tab[i], k)) {
                    findx(tab[i][2], a, tab, result, k);
                    (*k)--; // Backtrack
                }
            }
        }
    }
}

bool add_puzzle_to_result(int result[][3], int puzzle[], int *k) {
    if (*k < a) {
        for (int m = 0; m < 3; m++) {
            result[*k][m] = puzzle[m];
        }
        (*k)++;
        return true;
    }
    return false;
}

void print_result(int result[][3], int k) {
    printf("%d\n", k); // Number of puzzles in result
    for (int i = 0; i < k; i++) { // Print puzzles...
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n"); // ...in separate lines
    }
}
