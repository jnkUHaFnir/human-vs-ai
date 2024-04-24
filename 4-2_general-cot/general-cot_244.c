#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 50
#define GROWTH_FACTOR 2

void get_line(char* filename) {
    char* text = NULL;
    size_t text_size = INIT_SIZE;
    size_t text_length = 0;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file.\n");
        return;
    }

    text = malloc(sizeof(char) * text_size);
    if (text == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    int c;
    while ((c = fgetc(file)) != EOF && c != '\n') {
        text[text_length++] = (char)c;

        if (text_length == text_size - 1) {
            text_size *= GROWTH_FACTOR;
            char* temp = realloc(text, sizeof(char) * text_size);
            if (temp == NULL) {
                fprintf(stderr, "Memory reallocation failed.\n");
                free(text);
                text = NULL;
                break;
            }
            text = temp;
        }
    }

    text[text_length] = '\0';

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
