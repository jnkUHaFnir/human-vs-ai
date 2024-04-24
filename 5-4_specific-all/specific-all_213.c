#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int num, j;
    int* p;

    // Read the first line to get the number of integers
    if (fscanf(file, "%d", &num) != 1) {
        perror("Error reading number of integers");
        fclose(file);
        return 1;
    }

    // Allocate memory for the integers
    p = (int*)malloc(num * sizeof(int));
    if (p == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    // Read the integers from the second line
    for (j = 0; j < num; j++) {
        if (fscanf(file, "%d", &p[j]) != 1) {
            perror("Error reading integer");
            free(p);
            fclose(file);
            return 1;
        }
    }

    // Print the integers
    for (j = 0; j < num; j++) {
        printf("\t%d\t", p[j]);
    }
    printf("\n%d\n", num);

    // Free allocated memory and close the file
    free(p);
    fclose(file);

    return 0;
}
