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

    int *array = (int*)malloc(size * sizeof(int));

    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < size; i++)
    {
        array[i] = rand() % 100 + 1;
    }

    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    int largest = array[0];

    for (i = 1; i < size; i++)
    {
        if (largest < array[i])
        {
            largest = array[i];
        }
    }

    printf("\nLargest element present in the given array is: %d\n", largest);

    free(array); // Freeing allocated memory

    return 0;
}
