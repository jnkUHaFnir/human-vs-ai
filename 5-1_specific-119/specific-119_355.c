#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    int numIntegers, i;
    int* integers = NULL;

    // Read the first line to get the number of integers
    if (fscanf(file, "%d", &numIntegers) != 1) {
        fprintf(stderr, "Error reading number of integers\n");
        fclose(file);
        return 1;
    }

    // Allocate memory for the integers array
    integers = (int*)malloc(numIntegers * sizeof(int));
    if (integers == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return 1;
    }

    // Read integers from the second line
    for (i = 0; i < numIntegers; i++) {
        if (fscanf(file, "%d", &integers[i]) != 1) {
            fprintf(stderr, "Error reading integer\n");
            free(integers);
            fclose(file);
            return 1;
        }
    }

    // Print the integers read
    for (i = 0; i < numIntegers; i++) {
        printf("%d ", integers[i]);
    }
    printf("\n");

    // Clean up
    free(integers);
    fclose(file);

    return 0;
}
