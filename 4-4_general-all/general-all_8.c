#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int size;
  
    printf("\nSize of random array: ");
    scanf("%d", &size);

    int* array = (int*)malloc(size * sizeof(int)); // Dynamically allocate memory based on user input

    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100 + 1;;
    }

    printf("Random array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    int largest = array[0];

    for (int i = 1; i < size; i++) {
        if (largest < array[i]) {
            largest = array[i];
        }
    }

    printf("\nLargest element present in the given array is: %d\n", largest);

    free(array); // Don't forget to free the dynamically allocated memory

    return 0;
}
