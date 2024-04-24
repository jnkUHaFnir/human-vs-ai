#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 10

char* get_line(const char* filename) {
    char* text = NULL;
    size_t text_size = 0;
    size_t text_capacity = 0;

    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file\n");
        return NULL;
    }

    int c;
    while ((c = fgetc(file)) != EOF && c != '\n') {
        if (text_size == text_capacity) {
            text_capacity += CHUNK_SIZE;
            char* temp = realloc(text, text_capacity);
            if (!temp) {
                fclose(file);
                free(text);
                return NULL;
            }
            text = temp;
        }
        text[text_size++] = (char)c;
    }

    // Null-terminate the string
    if (text_size == text_capacity) {
        text_capacity++;
        char* temp = realloc(text, text_capacity);
        if (!temp) {
            fclose(file);
            free(text);
            return NULL;
        }
        text = temp;
    }
    text[text_size] = '\0';

    fclose(file);
    
    return text;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* line = get_line(argv[1]);
    if (line) {
        printf("The text was: %s\n", line);
        free(line);
    }

    return 0;
}
