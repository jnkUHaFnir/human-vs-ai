#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int size;
    int i;

    printf("\nSize of random array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int* array = (int*)malloc(size * sizeof(int));

    for (i = 0; i < size; i++)
    {
        array[i] = rand() % 100 + 1;
    }

    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    int largest = 0;

    for (i = 1; i < size; i++)
    {
        if (largest < array[i])
            largest = array[i];
    }
    printf("\n largest element present in the given array is : %d\n", largest);

    // Free the dynamically allocated memory
    free(array);

    return 0;
}
