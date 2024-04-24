#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    clock_t start = clock();

    FILE *stream;
    long fileSize;
    char *contents;
    int count;
    int *my_array;
    int i = 0;

    // Ensure filename is provided
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open file, find its size
    stream = fopen(argv[1], "rb");
    if (!stream) {
        perror("Error opening file");
        return 1;
    }
    fseek(stream, 0L, SEEK_END);
    fileSize = ftell(stream);
    fseek(stream, 0L, SEEK_SET);

    // Allocate space for file content
    contents = (char *)malloc(fileSize + 1);
    if (!contents) {
        fclose(stream);
        perror("Memory allocation failed");
        return 1;
    }

    // Read file into memory and null-terminate the string
    fread(contents, 1, fileSize, stream);
    contents[fileSize] = '\0';
    fclose(stream);

    // Parse the size from the first line
    sscanf(contents, "%d\n", &count);
    my_array = (int *)malloc(count * sizeof(int));
    if (!my_array) {
        free(contents);
        perror("Memory allocation failed");
        return 1;
    }

    // Tokenize and parse numbers from the second line
    char *token = strtok(contents + (int)(log10(count) + 2), " ");
    while (token != NULL && i < count) {
        my_array[i++] = atoi(token);
        token = strtok(NULL, " ");
    }

    float seconds = (float)(clock() - start) / CLOCKS_PER_SEC;

    printf("Took %fs\n", seconds);

    // Cleanup
    free(contents);
    free(my_array);

    return 0;
}
