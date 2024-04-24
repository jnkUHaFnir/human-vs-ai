#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    clock_t start;
    float seconds;
    int *numbers;
    int array_size;
    start = clock();

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Read array size
    fscanf(file, "%d", &array_size);

    // Allocate memory for array
    numbers = (int *)malloc(array_size * sizeof(int));

    // Error handling for memory allocation
    if (numbers == NULL)
    {
        printf("Error allocating memory!\n");
        fclose(file);
        return 1;
    }

    // Read numbers
    for (int i = 0; i < array_size; i++)
    {
        fscanf(file, "%d", &numbers[i]);
    }

    // Close file and free memory
    fclose(file);
    free(numbers);

    seconds = (float)(clock() - start) / CLOCKS_PER_SEC;
    printf("Took %fs\n", seconds);

    return 0;
}
