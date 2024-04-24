#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int num_elements, i;
    int* elements;

    // Read the number of elements from the file
    fscanf(file, "%d", &num_elements);

    // Allocate memory for the elements
    elements = (int*)malloc(num_elements * sizeof(int));
    if (elements == NULL) {
        perror("Error allocating memory");
        return 1;
    }

    // Read the elements from the file
    for (i = 0; i < num_elements; i++) {
        fscanf(file, "%d", &elements[i]);
    }

    // Close the file
    fclose(file);

    // Print the elements
    printf("Elements read from file:\n");
    for (i = 0; i < num_elements; i++) {
        printf("%d ", elements[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(elements);

    return 0;
}
