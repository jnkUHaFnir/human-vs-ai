#include "stdio.h"
#include "stdlib.h"
#define INIT_SIZE 50
#define INCR_SIZE 10  // Buffer size increment when reallocating

void get_line (char* filename) {
    char* text;
    FILE* file = fopen(filename,"r");
    if (!file) {
        printf("Unable to open file!\n");
        return;
    }

    int buf_size = INIT_SIZE;
    text = malloc(sizeof(char) * buf_size);
    if (!text) {
        printf("Memory allocation failed!\n");
        return;
    }

    char* result;
    do {
        result = fgets(text + buf_size - INIT_SIZE, INIT_SIZE, file);

        // Check if buffer was filled (excluding null terminator)
        if (result && text[buf_size - 2] != '\n' && !feof(file)) {
            buf_size += INCR_SIZE;
            char* new_text = realloc(text, buf_size);
            if (!new_text) {
                printf("Memory allocation failed!\n");
                free(text);
                return;
            }
            text = new_text;
        }
    } while (result && text[buf_size - 2] != '\n' && !feof(file));

    printf("The text was: %s\n", text);
    fclose(file);
    free(text);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        get_line(argv[1]);
    } else {
        printf("No file name provided!\n");
    }
    return 0;
}
