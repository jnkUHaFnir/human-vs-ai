#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("files.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int first_num, j;
    int* p;

    // Read the first number from the file
    fscanf(file, "%d", &first_num);

    // Allocate memory for the array
    p = (int*)malloc(first_num * sizeof(int));

    // Read integers from the file
    for (j = 0; j < first_num; j++) {
        fscanf(file, "%d", &p[j]);
    }

    // Print the integers
    for (j = 0; j < first_num; j++) {
        printf("\t%d\t", p[j]);
    }
    printf("\n%d\n", first_num);

    // Free dynamically allocated memory
    free(p);

    fclose(file);

    return 0;
}
