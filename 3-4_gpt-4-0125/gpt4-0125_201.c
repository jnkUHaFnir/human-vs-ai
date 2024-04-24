#include<stdio.h>
#include<stdlib.h>

int main() {
    int initialSize = 10;
    int *p = (int*)malloc(initialSize * sizeof(int)); // It's good practice to use sizeof(int)
    if (!p) { // Always check if memory allocation was successful
        printf("Memory allocation failed\n");
        return 1;
    }
    
    int i = 0; // Index for the loop
    printf("Input :\n");
    while (1) {
        scanf("%d", &p[i]);
        if (p[i] == 22) { // If 22 is encountered, stop taking inputs
            break;
        }
        i++;
        if (i >= initialSize) { // Increase the size of array if limit is reached
            initialSize += 10; // Increase by 10
            int *newPtr = realloc(p, initialSize * sizeof(int)); // Use realloc to adjust memory allocation
            if (!newPtr) { // Always check if reallocation was successful
                printf("Memory reallocation failed\n");
                free(p); // Free the previously allocated memory
                return 1;
            }
            p = newPtr;
        }
    }

    printf("\nOutput :\n");
    for (int j = 0; j < i; j++) { // Use the counter 'i' as the upper limit for printing
        printf("%d\n", p[j]);
    }

    free(p); // Don't forget to free the allocated memory
    return 0;
}
