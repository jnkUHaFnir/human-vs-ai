#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 50

void get_line(char* filename) {
    char* text = malloc(sizeof(char) * INIT_SIZE);
    if (text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file\n");
        free(text);
        return;
    }

    int allocated_size = INIT_SIZE;
    int used_size = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF && ch != '\n') {
        text[used_size++] = (char)ch;

        if (used_size == allocated_size - 1) {
            allocated_size *= 2;
            char* temp = realloc(text, allocated_size);
            if (temp == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                free(text);
                fclose(file);
                return;
            }
            text = temp;
        }
    }
    text[used_size] = '\0';  // Null-terminate the string

    printf("The text was: %s\n", text);

    fclose(file);
    free(text);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    get_line(argv[1]);

    return 0;
}
