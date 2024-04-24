#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 50
#define CHUNK_SIZE 10

void get_line(char *filename) {
    char *text = NULL;
    int text_size = INIT_SIZE;
    int text_length = 0;

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    text = malloc(sizeof(char) * text_size);
    if (text == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    char chunk[CHUNK_SIZE];
    while (fgets(chunk, CHUNK_SIZE, file) != NULL) {
        int chunk_length = strlen(chunk);

        if ((text_length + chunk_length) >= text_size) {
            text_size += chunk_length + 1;  // +1 for null terminator
            text = realloc(text, text_size);
            if (text == NULL) {
                perror("Memory reallocation failed");
                exit(1);
            }
        }

        strcat(text, chunk);
        text_length += chunk_length;

        if (text[text_length - 1] == '\n' || text[text_length - 1] == EOF) {
            break;
        }
    }

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
