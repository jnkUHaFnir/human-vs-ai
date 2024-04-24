#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 50
#define INCREMENT_SIZE 10

void get_line(char* filename) {
    char* text = NULL;
    size_t current_size = INIT_SIZE; // Initial size of the buffer
    size_t current_length = 0; // Current length of the string

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    text = malloc(sizeof(char) * current_size);

    if (text == NULL) {
        perror("Error allocating memory");
        return;
    }

    char* result = fgets(text, INIT_SIZE, file);
    while (result != NULL) {
        current_length += strlen(text);
        if (text[current_length - 1] == '\n') {
            break; // Stop reading at newline
        }

        char* new_text = realloc(text, current_size + INCREMENT_SIZE);
        if (new_text == NULL) {
            perror("Error reallocating memory");
            break;
        }

        text = new_text;
        result = fgets(text + current_length, INCREMENT_SIZE, file);
    }

    printf("The text was: %s\n", text);

    free(text);
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    get_line(argv[1]);

    return 0;
}
