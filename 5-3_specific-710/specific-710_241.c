#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 10

void get_line(char *filename) {
    char *text = NULL;
    size_t text_size = 0;
    size_t text_len = 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return;
    }

    int c;
    while ((c = fgetc(file)) != '\n' && c != EOF) {
        text_len++;
        if (text_len >= text_size) {
            text_size += CHUNK_SIZE;
            text = realloc(text, sizeof(char) * text_size);
            if (text == NULL) {
                fprintf(stderr, "Error reallocating memory\n");
                break;
            }
        }
        text[text_len - 1] = (char)c;
    }

    text[text_len] = '\0'; // Null-terminate the string

    printf("The text was: %s\n", text);

    free(text);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    get_line(argv[1]);

    return 0;
}
