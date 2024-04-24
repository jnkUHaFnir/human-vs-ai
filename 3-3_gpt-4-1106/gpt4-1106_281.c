#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int array[n]; // Declaring a VLA (Variable Length Array)

    // Use the array here, for example, initializing it
    for(int i = 0; i < n; i++){
        array[i] = i;
    }

    // Printing the array
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }

    return 0;
}

or to ensure the maximum portability across different C11 standard compilers, use:

```bash
gcc -std=c11 -pedantic -o my_program my_program.c
