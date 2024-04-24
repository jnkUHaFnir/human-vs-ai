#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start = clock();
    FILE *fp = fopen("ooo.txt", "r");
    
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1; // Return with failure
    }

    int t_size;
    fscanf(fp, "%d", &t_size);

    int* my_array = malloc(t_size * sizeof(int));
    if (my_array == NULL) {
        printf("Error allocating memory!\n");
        return 1; // Return with failure
    }

    for (int i = 0; i < t_size; i++) {
        fscanf(fp, "%d", &my_array[i]);
    }

    fclose(fp);

    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Read and stored numbers in %f seconds.\n", elapsed_time);

    // Perform operations with my_array here

    free(my_array); // Free dynamically allocated memory

    return 0;
}
