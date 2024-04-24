#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 50
#define CHUNK_SIZE 50

void get_line(char* filename) {
    char *text, *temp;
    int currentSize = INIT_SIZE;
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("File could not be opened.\n");
        return;
    }

    text = malloc(sizeof(char) * INIT_SIZE);
    if (!text) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return;
    }

    text[0] = '\0'; // Initialize the buffer to an empty string

    while (!feof(file) && !ferror(file)) {
        if (fgets(text + strlen(text), CHUNK_SIZE, file) == NULL) {
            break;
        }

        // If the last character is not '\n', it could be either EOF or line longer than buffer.
        if (text[strlen(text) - 1] != '\n') {
            currentSize += CHUNK_SIZE - 1; // -1 to overwrite the '\0' added by fgets
            temp = realloc(text, currentSize);
            if (!temp) {
                printf("Memory reallocation failed.\n");
                free(text);
                fclose(file);
                return;
            }
            text = temp;
        } else {
            break; // New line character found, quit loop
        }
    }

    printf("The text was: %s\n", text);

    free(text);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a filename as an argument.\n");
        return 1;
    }

    get_line(argv[1]);

    return 0;
}

