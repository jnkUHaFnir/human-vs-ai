#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int size;
    
    printf("\nSize of random array: ");
    scanf("%d", &size);

    int *array = (int *)malloc(size * sizeof(int)); // Dynamically allocate memory for the array based on user input size

    if (array == NULL) {
        printf("Memory allocation failed. Exiting.");
        return 1;
    }

    for (int i = 0; i < size; i++){
        array[i] = rand() % 100 + 1;
    }

    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }

    int largest = array[0]; // Initialize largest with the first element of the array

    for (int i = 1; i < size; i++)
    {
        if (largest < array[i])
            largest = array[i];
    }

    printf("\n largest element present in the given array is : %d\n", largest);

    free(array); // Free dynamically allocated memory

    return 0;
}
