#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 50
#define INCREMENT 50

void get_line(char* filename) {
    char* text = NULL;
    size_t size = 0;
    size_t length = 0;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return;
    }

    text = malloc(sizeof(char) * INIT_SIZE);
    size = INIT_SIZE;

    if (text == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        fclose(file);
        return;
    }

    while (fgets(text + length, size - length, file) != NULL) {
        length += strlen(text + length);

        if (text[length - 1] == '\n') {
            // Line read successfully
            break;
        }

        if (length + 1 >= size) {
            size += INCREMENT;
            char* tmp = realloc(text, size);
            if (tmp == NULL) {
                fprintf(stderr, "Memory reallocation error\n");
                break;
            }
            text = tmp;
        }
    }

    text[length] = '\0'; // Null-terminate the string

    printf("The text was: %s\n", text);

    free(text);
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    get_line(argv[1]);

    return 0;
}
