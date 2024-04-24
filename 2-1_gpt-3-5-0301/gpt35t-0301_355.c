#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    int target_line = 2;  // the line number to read from
    int line_num = 1;     // current line number
    int num_ints;         // number of integers on target line
    int* ints = NULL;     // pointer to array of integers

    // loop through file until target line is reached
    while (line_num < target_line) {
        if (fscanf(file, "%*[^\n]\n") == EOF) {
            printf("Error: Target line not found\n");
            fclose(file);
            return 1;
        }
        line_num++;
    }

    // read number of integers on target line
    if (fscanf(file, "%d", &num_ints) != 1) {
        printf("Error: Failed to read number of integers\n");
        fclose(file);
        return 1;
    }
    ints = malloc(num_ints * sizeof(int));

    // read integers from target line
    for (int i = 0; i < num_ints; i++) {
        if (fscanf(file, "%d", &ints[i]) != 1) {
            printf("Error: Failed to read integer\n");
            free(ints);
            fclose(file);
            return 1;
        }
    }

    // print integers for testing
    for (int i = 0; i < num_ints; i++) {
        printf("%d ", ints[i]);
    }
    printf("\n");

    free(ints);
    fclose(file);

    return 0;
}
