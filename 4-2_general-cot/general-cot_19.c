#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int size;
    int *array; 
} CustomArray;

CustomArray createCustomArray(int size) {
    CustomArray customArray;
    customArray.size = size;
    customArray.array = (int*)malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (customArray.array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    return customArray;
}

int main() {
    int size = 5;
    CustomArray myCustomArray = createCustomArray(size);

    // Access and modify elements
    for (int i = 0; i < myCustomArray.size; i++) {
        myCustomArray.array[i] = i * 2;
    }

    // Print elements
    for (int i = 0; i < myCustomArray.size; i++) {
        printf("myCustomArray.array[%d] = %d\n", i, myCustomArray.array[i]);
    }

    // Free memory when done
    free(myCustomArray.array);

    return 0;
}
