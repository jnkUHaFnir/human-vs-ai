#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("file.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int num, i;
    fscanf(file, "%d", &num);  // Read the number of integers from the first line

    int* arr = (int*)malloc(num * sizeof(int)); // Allocate memory for the integers

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Read integers from the second line and store them in the array
    for (i = 0; i < num; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    // Output the integers in the array
    for (i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Free the allocated memory
    fclose(file);

    return 0;
}
