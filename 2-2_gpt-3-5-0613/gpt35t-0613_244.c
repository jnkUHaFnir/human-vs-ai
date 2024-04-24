#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 50

void get_line (char* filename) {
    char* text;
    unsigned int size = INIT_SIZE; // Variable to keep track of the allocated memory size
    unsigned int length = 0;       // Variable to keep track of the total length of the text

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    text = malloc(sizeof(char) * size);
    if (text == NULL) {
        printf("Error allocating memory\n");
        fclose(file);
        return;
    }

    char* line = fgets(text, size, file); // Read the first line
    while (line != NULL) {
        length += strlen(line); // Update the total length

        // Check if more memory is needed
        if (length >= size - 1) { // -1 to leave space for the null terminator
            size *= 2; // Double the size
            char* new_text = realloc(text, sizeof(char) * size);
            if (new_text == NULL) {
                printf("Error reallocating memory\n");
                free(text);
                fclose(file);
                return;
            }
            text = new_text; // Update the pointer to the newly allocated memory
        }

        line = fgets(text + length, size - length, file); // Read the next line after the current position

        // Check for EOF or newline character
        if (line != NULL && (line[strlen(line)-1] == '\n' || line[strlen(line)-1] == EOF)) {
            break;
        }
    }

    text[length] = '\0';

    printf("The text was: %s\n", text);

    free(text);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    get_line(argv[1]);

    return 0;
}
