#include "stdio.h"
#include "stdlib.h"

#define INIT_SIZE 50
#define READ_SIZE 10  // Define a smaller chunk size for subsequent reads

void get_line(char* filename) {
    char *text;
    int current_size = INIT_SIZE;
    FILE* file = fopen(filename, "r");

    if (!file) {
        fprintf(stderr, "File cannot be opened.\n");
        return;
    }

    text = malloc(sizeof(char) * current_size);
    if (!text) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        return;
    }

    int position = 0; // Keep track of where to start reading into the buffer
    while (fgets(text + position, READ_SIZE, file)) {
        // Check if the current chunk contains '\n' or EOF
        size_t len = strlen(text + position);
        if (text[position + len - 1] == '\n') {
            break; // Line end found
        }
        position += len;  // Advance the position
        current_size += READ_SIZE;  // Plan to increase the buffer size
        char* new_memory = realloc(text, current_size);
        if (!new_memory) {
            fprintf(stderr, "Memory reallocation failed.\n");
            free(text);
            fclose(file);
            return;
        }
        text = new_memory;
    }

    printf("The text was: %s\n", text);

    free(text);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    get_line(argv[1]);
    return 0;
}
