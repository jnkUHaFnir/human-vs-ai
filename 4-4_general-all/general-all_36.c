#include <stdio.h>

void findx(int x, int a, int (*tab)[3], int (*result)[3], int k);

void print_result(int (*result)[3], int k);

int main() {
    int a;
    scanf("%d", &a); // Number of puzzles
    int tab[a][3];
    int result[100][3]; // Assuming maximum 100 valid results
    int k = 0;

    for(int i = 0; i < a; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &tab[i][j]);
        }
    }

    findx(0, a, tab, result, k);
    return 0;
}

void findx(int x, int a, int (*tab)[3], int (*result)[3], int k) {
    for(int i = 0; i < a; i++) {
        if(tab[i][0] == x) { 
            if(tab[i][1] == 0) {
                for(int m = 0; m < 3; m++) {
                    result[k][m] = tab[i][m];
                }
                print_result(result, k);
                return;
            } else {
                for(int m = 0; m < 3; m++) {
                    result[k][m] = tab[i][m];
                }
                findx(tab[i][1], a, tab, result, k+1);
            }
        }
    }
    printf("no result\n");
}

void print_result(int (*result)[3], int k) {
    printf("%d\n", k+1); // Number of puzzles
    for(int i = 0; i <= k; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
