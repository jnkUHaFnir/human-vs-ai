#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE *file = fopen("ooo.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int size;
    if (fscanf(file, "%d", &size) != 1) {
        fprintf(stderr, "Failed to read the size from the file\n");
        fclose(file);
        return 1;
    }

    int* my_array = (int*)malloc(size * sizeof(int));
    if (my_array == NULL) {
        fprintf(stderr, "Error allocating memory for the array\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < size; i++) {
        if (fscanf(file, "%d", &my_array[i]) != 1) {
            fprintf(stderr, "Failed to read number #%d from the file\n", i + 1);
            free(my_array);
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    // Print array elements for verification
    printf("Array contents:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");

    free(my_array);
    return 0;
}
