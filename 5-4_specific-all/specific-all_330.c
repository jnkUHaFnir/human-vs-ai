#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    clock_t start;
    unsigned long microseconds;
    float seconds;

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int t_size;
    fscanf(file, "%d", &t_size); // Read the size of the array
    
    if (t_size <= 0) {
        printf("Invalid array size.\n");
        fclose(file);
        return 1;
    }

    int* my_array = (int*)malloc(t_size * sizeof(int));
    if (my_array == NULL) {
        printf("Error allocating memory!\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < t_size; i++) {
        fscanf(file, "%d", &my_array[i]); // Read numbers directly into the array
    }

    fclose(file);

    start = clock();

    // Your code to measure time
    
    microseconds = clock() - start;
    seconds = microseconds / 1000000.0f;
    printf("Took %fs\n", seconds);

    // Code to verify the numbers are read correctly
    /*
    printf("Array elements:\n");
    for (int i = 0; i < t_size; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");
    */

    free(my_array); // Don't forget to free the allocated memory

    return 0;
}
