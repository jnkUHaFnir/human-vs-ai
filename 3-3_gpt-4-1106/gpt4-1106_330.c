#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start = clock();
    FILE *fp;
    const char *filename = "ooo.txt";
    int array_size, i, read_count;

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the first line to get the size of the array
    if (fscanf(fp, "%d", &array_size) != 1 || array_size <= 0) {
        fprintf(stderr, "Failed to read array size or invalid size\n");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Allocate memory for the array
    int *array = (int *)malloc(array_size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Failed to allocate memory for the array\n");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Read the second line containing the numbers 
    for (i = 0; i < array_size; i++) {
        read_count = fscanf(fp, "%d", &array[i]);
        if (read_count != 1) {
            fprintf(stderr, "Failed to read numbers or file is corrupted\n");
            free(array);
            fclose(fp);
            return EXIT_FAILURE;
        }
    }

    // Close the file
    fclose(fp);

    // Optionally, do something with your array here
    // For example, print the first 10 numbers for verification
    /*
    for (i = 0; i < 10 && i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    */

    // Free the allocated array
    free(array);

    clock_t end = clock();
    double seconds_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Took %f seconds\n", seconds_spent);

    return EXIT_SUCCESS;
}
