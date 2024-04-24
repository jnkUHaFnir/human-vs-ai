#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define INIT_SIZE 50

void get_line (char* filename) {
    char* text;
    FILE* file = fopen(filename, "r");

    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    int bufferSize = INIT_SIZE;

    text = malloc(sizeof(char) * bufferSize);
    
    // Check if the memory allocation was successful
    if (!text) {
        printf("Error: Unable to allocate memory.\n");
        return;
    }

    int i = 0;

    while (fgets(text + i, bufferSize - i, file) != NULL) {
        // If the last character read is not a newline, it means the buffer is full
        if (text[strlen(text) - 1] != '\n') {
            bufferSize *= 2; // Double the buffer size
            text = realloc(text, bufferSize);

            // Check if the reallocation was successful
            if (!text) {
                printf("Error: Unable to reallocate memory.\n");
                return;
            }

            i = strlen(text);
        } else {
            break; // The entire line has been read
        }
    }

    printf("The text was: %s", text);

    fclose(file);
    free(text);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    get_line(argv[1]);

    return 0;
}
