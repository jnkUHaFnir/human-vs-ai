#include <stdio.h>
#include <stdlib.h>

int findx(int x, int a, int tab[][3], int result[][3], int k);
int print_result(int result[][3], int k);

int main() {
    int a;
    scanf("%d", &a);
    int (*tab)[3] = malloc(a * sizeof(*tab)); // allocate memory for puzzles
    int result[a][3];
    int k = 0;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &tab[i][j]);
        }
    }

    findx(0, a, tab, result, &k);
    free(tab); // free memory after use
    return 0;
}

int findx(int x, int a, int tab[][3], int result[][3], int *k) {
    for (int i = 0; i < a; i++) {
        if (tab[i][0] == x) {
            if (tab[i][2] == 0) {
                for (int m = 0; m < 3; m++) {
                    result[*k][m] = tab[i][m];
                }
                (*k)++;
                print_result(result, *k);
            } else {
                for (int m = 0; m < 3; m++) {
                    result[*k][m] = tab[i][m];
                }
                (*k)++;
                findx(tab[i][2], a, tab, result, k);
            }
        }
    }
    printf("no result\n");
    return 0;
}

int print_result(int result[][3], int k) {
    printf("%d\n", k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
