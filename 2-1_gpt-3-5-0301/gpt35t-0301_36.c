int **result = malloc(a * sizeof(int *));
for (int i = 0; i < a; i++) {
    result[i] = malloc(3 * sizeof(int));
}
int findx(int x, int a, int **tab, int **result, int k);
void print_result(int **result, int k);
int findx(int x, int a, int **tab, int **result, int k) {
    bool found = false;
    for (int i = 0; i < a; i++) {
        if (tab[i][0] == x) {
            if (tab[i][2] == 0) {
                // found a solution
                for (int m = 0; m < 3; m++) {
                    result[k][m] = tab[i][m];
                }
                print_result(result, k + 1);
                found = true;
                break;
            }
            else {
                // add puzzle to result and continue recursion
                for (int m = 0; m < 3; m++) {
                    result[k][m] = tab[i][m];
                }
                findx(tab[i][2], a, tab, result, k + 1);
            }
        }
    }
    if (!found) {
        printf("no result\n");
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
int main() {
    int a;
    scanf("%d", &a);
    int **tab = malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++) {
        tab[i] = malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++) {
            scanf("%d", &tab[i][j]);
        }
    }
    int **result = malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++) {
        result[i] = malloc(3 * sizeof(int));
    }
    findx(0, a, tab, result, 0);
    return 0;
}
