#include <stdio.h>
#include <stdlib.h> // For dynamic memory allocation

// Function declarations
int findx(int x, int a, int tab[][3], int result[][3], int k);
void print_result(int result[][3], int k);

int main() {

    int a;
    scanf("%d", &a);

    int tab[a][3];
    int k = 0;

    for(int i = 0; i < a; i++){
        for(int j = 0; j < 3; j++) {
            scanf("%d", &tab[i][j]);
        }
    }

    // Dynamically allocate memory for the result array
    int **result = (int **)malloc(a * sizeof(int *));
    for(int i = 0; i < a; i++) {
        result[i] = (int *)malloc(3 * sizeof(int));
    }

    findx(0, a, tab, result, k);

    // Free dynamically allocated memory
    for(int i = 0; i < a; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}

int findx(int x, int a, int tab[][3], int result[][3], int k) {
    // Function implementation
}

void print_result(int result[][3], int k) {
    // Function implementation
}
