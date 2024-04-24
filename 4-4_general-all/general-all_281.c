#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    // Check for valid input
    if (n <= 0) {
        printf("Invalid array size\n");
        return 1;
    }

    int *array = malloc(n * sizeof(int));
    
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Use the array

    // Don't forget to free the allocated memory when you're done
    free(array);

    return 0;
}
