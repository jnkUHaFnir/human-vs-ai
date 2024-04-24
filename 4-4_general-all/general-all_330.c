#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]) {
    clock_t start;
    double duration;

    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int count, i;
    int* my_array;

    start = clock();
    
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the first line containing the count
    if ((read = getline(&line, &len, fp)) != -1) {
        count = atoi(line);
        my_array = (int*)malloc(count * sizeof(int));

        // Read and store numbers from the second line
        for (i = 0; i < count; i++) {
            if ((read = getline(&line, &len, fp)) != -1) {
                my_array[i] = atoi(line);
            } else {
                fprintf(stderr, "Error reading numbers from file\n");
                return 1;
            }
        }
    } else {
        fprintf(stderr, "Error reading file\n");
        return 1;
    }

    fclose(fp);
    if (line) {
        free(line);
    }

    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Took %f seconds\n", duration);

    // Use the data in my_array as needed

    free(my_array);
    return 0;
}
