#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int size;
    int i;

    printf("\nSize of random array: ");
    scanf("%d", &size);

    int *array = malloc(size * sizeof(int)); // Dynamically allocated array based on user input

    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < size; i++){
        array[i] = rand() % 100 + 1;
    }

    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    int largest = array[0]; // Initialize largest with first element of array

    for (i = 1; i < size; i++) {
        if (largest < array[i]) {
              largest = array[i];
        }
    }
    printf("\nlargest element present in the given array is : %d\n", largest);

    free(array); // Free the dynamically allocated memory
    return 0;
}
