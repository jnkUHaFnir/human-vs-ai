#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *array = malloc(n * sizeof(int));
    
    if(array == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Use the array

    // Don't forget to free the allocated memory when done
    free(array);

    return 0;
}
