#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start;
    float seconds;
    
    FILE *fp = fopen("ooo.txt", "r");  // Open the file for reading
    if (fp == NULL) {
        printf("Error opening the file!\n");
        return 1;
    }
    
    int t_size;
    fscanf(fp, "%d", &t_size); // Read the size of the array
    
    int* my_array = (int*)malloc(t_size * sizeof(int)); // Allocate memory for the array
    if (my_array == NULL) {
        printf("Error allocating memory!\n");
        return 1;
    }
    
    for (int i = 0; i < t_size; i++) {
        fscanf(fp, "%d", &my_array[i]); // Read numbers and store in the array
    }

    fclose(fp); // Close the file
    
    // Measure the time taken
    start = clock();
    
    // Your processing code here

    seconds = (float)(clock() - start) / CLOCKS_PER_SEC;
    printf("Took %fs\n", seconds);

    // Free dynamically allocated memory
    free(my_array);

    return 0;
}
