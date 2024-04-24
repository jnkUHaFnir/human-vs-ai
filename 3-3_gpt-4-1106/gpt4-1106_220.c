#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &m, &n);
    int *arr = malloc(sizeof(int) * n * m);
    
    for (int i = 0; i < m * n; scanf("%d", arr + i), i++);
    
    // Your immediate printf should be here
    printf("The array has been filled.\n");

    // ... rest of the program

    free(arr); // Remember to free dynamically allocated memory
    return 0;
}
