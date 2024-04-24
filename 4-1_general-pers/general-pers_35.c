#include <stdio.h>

int findx(int x, int a, int tab[][3], int result[][3], int k);
void print_result(int result[][3], int k);

int main() {
    // your main function code here
}
int **result = malloc(sizeof(int*) * MAX_PUZZLES);
for (int i = 0; i < MAX_PUZZLES; i++) {
    result[i] = malloc(sizeof(int) * 3);
}
for (int i = 0; i < MAX_PUZZLES; i++) {
    free(result[i]);
}
free(result);
