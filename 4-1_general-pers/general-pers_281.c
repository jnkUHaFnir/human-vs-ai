#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size\n");
        return 1; // Return an error code
    }

    int *array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Return an error code
    }

    // Use the array

    free(array); // Don't forget to free the memory when you're done with it

    return 0;
}
