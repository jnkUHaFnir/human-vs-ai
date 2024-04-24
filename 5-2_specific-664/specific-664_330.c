#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]) {
    clock_t start;
    unsigned long microseconds;
    float seconds;

    start = clock();

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    // Read the size of the array
    int count;
    if (fscanf(file, "%d", &count) != 1) {
        fprintf(stderr, "Error reading array size\n");
        fclose(file);
        return 1;
    }

    // Allocate memory for the array
    int *my_array = malloc(count * sizeof(int));
    if (my_array == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        fclose(file);
        return 1;
    }

    // Read the array elements
    for (int i = 0; i < count; i++) {
        if (fscanf(file, "%d", &my_array[i]) != 1) {
            fprintf(stderr, "Error reading array element at index %d\n", i);
            free(my_array);
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    microseconds = clock() - start;
    seconds = microseconds / 1000000.0f;
    printf("Took %fs\n", seconds);

    // Use the array as needed

    // Don't forget to free the allocated memory
    free(my_array);

    return 0;
}
