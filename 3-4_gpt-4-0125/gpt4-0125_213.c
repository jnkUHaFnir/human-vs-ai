#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("files.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int num = 0;
    // Read the number of integers from the first line
    if (fscanf(file, "%d", &num) != 1) {
        // Handle error if the number couldn't be read
        fclose(file);
        printf("Failed to read the number of integers\n");
        return 1;
    }

    // Allocate memory based on the number read
    int* p = (int*)malloc(num * sizeof(int));
    if (p == NULL) {
        // Handle memory allocation failure
        fclose(file);
        printf("Memory allocation failed\n");
        return 1;
    }

    // Read the integers from the second line
    for (int i = 0; i < num; i++) {
        if (fscanf(file, "%d", &p[i]) != 1) {
            // Handle error if an integer couldn't be read
            free(p);
            fclose(file);
            printf("Failed to read integer %d\n", i + 1);
            return 1;
        }
    }

    // Do something with the integers
    for (int i = 0; i < num; i++) {
        printf("\t%d\t", p[i]);
    }
    printf("\nNumber of integers: %d\n", num);

    // Free allocated memory and close the file
    free(p);
    fclose(file);

    return 0;
}
