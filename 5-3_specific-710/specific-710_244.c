#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 50

char* readline(FILE* file) {
    int current_size = INIT_SIZE;
    int i = 0;
    char* line = (char*)malloc(current_size * sizeof(char));
    int c;

    if (line == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = fgetc(file);

        if (c == EOF || c == '\n') {
            line[i] = '\0';  // Null-terminate the string
            break;
        }

        line[i] = (char)c;
        i++;

        if (i == current_size - 1) {
            current_size *= 2;
            char* temp = realloc(line, current_size * sizeof(char));
            if (temp == NULL) {
                free(line);
                fprintf(stderr, "Memory reallocation failed.\n");
                exit(EXIT_FAILURE);
            } else {
                line = temp;
            }
        }
    }

    return line;
}

void get_line(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "File not found.\n");
        exit(EXIT_FAILURE);
    }

    char* text = readline(file);

    printf("The text was: %s\n", text);

    free(text);
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    get_line(argv[1]);

    return 0;
}
