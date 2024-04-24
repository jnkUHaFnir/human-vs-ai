int array[0];
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));

    int size;
    int i;

    printf("\nSize of random array: ");
    scanf("%d", &size);

    // Define the array with the correct size
    int array[size];

    for (i = 0; i < size; i++) {
        array[i] = rand() % 100 + 1;
    }

    printf("Random array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    int largest = array[0];

    for (i = 1; i < size; i++) {
        if (largest < array[i]) {
            largest = array[i];
        }
    }
    printf("\n Largest element present in the given array is : %d\n", largest);

    return 0;
}
