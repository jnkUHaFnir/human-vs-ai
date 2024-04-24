#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 50
#define CHUNK_SIZE 10

char* get_line(char* filename) {
    char* text;
    int current_size = INIT_SIZE;
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        return NULL;
    }

    text = malloc(sizeof(char) * current_size);
    if (!text) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    text[0] = '\0'; // Initialize the C string
    char buffer[CHUNK_SIZE];
    while (fgets(buffer, CHUNK_SIZE, file)) {
        int chunk_len = strlen(buffer);
        int text_len = strlen(text);

        // Check if the buffer was filled without encountering a newline or EOF
        if (text_len + chunk_len >= current_size) {
            current_size += CHUNK_SIZE; // Increase the memory allocation
            text = realloc(text, sizeof(char) * current_size);
            if (!text) {
                fprintf(stderr, "Memory reallocation failed\n");
                fclose(file);
                return NULL;
            }
        }
        
        // Append the new chunk to what we've read so far
        strcat(text, buffer);

        // Check if we encountered a newline or EOF
        if (buffer[chunk_len - 1] == '\n' || feof(file)) {
            break;
        }
    }

    fclose(file);
    return text; // Return the dynamically allocated line
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* line = get_line(argv[1]);
    if (line) {
        printf("The text was: %s", line);
        free(line);
    }

    return EXIT_SUCCESS;
}
