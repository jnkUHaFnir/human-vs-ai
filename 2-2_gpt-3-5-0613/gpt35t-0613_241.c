#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 50

void get_line(char* filename) {
    char* text;
    int size = INIT_SIZE;
    int current = 0;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file\n");
        return;
    }

    text = malloc(sizeof(char) * size);
    if (text == NULL) {
        printf("Unable to allocate memory\n");
        return;
    }

    while (fgets(&text[current], size - current, file) != NULL) {
        current += strlen(&text[current]);

        if (text[current - 1] == '\n') { // reached end of line
            text[current - 1] = '\0'; // replace newline with null character
            break;
        }

        size += INIT_SIZE;
        text = realloc(text, sizeof(char) * size);
        if (text == NULL) {
            printf("Unable to reallocate memory\n");
            free(text); // don't forget to free the memory before returning
            return;
        }
    }

    printf("The text was %s\n", text);
    free(text);
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Please provide a filename\n");
        return 1;
    }

    get_line(argv[1]);

    return 0;
}
