#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    int numIntegers, intValue;
    if (fscanf(file, "%d", &numIntegers) != 1) {
        fprintf(stderr, "Error reading number of integers.\n");
        fclose(file);
        return 1;
    }

    int* integers = (int*)malloc(numIntegers * sizeof(int));
    if (integers == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < numIntegers; i++) {
        if (fscanf(file, "%d", &intValue) == 1) {
            integers[i] = intValue;
        } else {
            fprintf(stderr, "Error reading integer values.\n");
            free(integers);
            fclose(file);
            return 1;
        }
    }

    // Print the integers
    for (int i = 0; i < numIntegers; i++) {
        printf("%d ", integers[i]);
    }
    printf("\n");

    free(integers);
    fclose(file);

    return 0;
}
