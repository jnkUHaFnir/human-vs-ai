#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to read integer array from file
int* readIntArrayFromFile(const char* filename, int* size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read size of the array
    if (fscanf(file, "%d", size) != 1) {
        fprintf(stderr, "Error reading size from file.\n");
        fclose(file);
        return NULL;
    }

    // Allocate memory for the array
    int* array = malloc(*size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Error allocating memory for array.\n");
        fclose(file);
        return NULL;
    }

    // Read numbers into the array
    for (int i = 0; i < *size; i++) {
        if (fscanf(file, "%d", &array[i]) != 1) {
            fprintf(stderr, "Error reading number in position %d.\n", i);
            free(array);
            fclose(file);
            return NULL;
        }
    }

    fclose(file);
    return array;
}

int main() {
    clock_t start = clock();
    
    int size;
    int* my_array = readIntArrayFromFile("ooo.txt", &size);
    
    if (my_array == NULL) {
        return 1; // Exit if failed to read array
    }

    double elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Array of size %d read from file in %.6f seconds\n", size, elapsed);

    // Use the array as needed

    free(my_array); // Free the allocated memory

    return 0;
}
