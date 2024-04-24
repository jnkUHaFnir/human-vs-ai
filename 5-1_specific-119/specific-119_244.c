#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 50
#define INCREMENT_SIZE 10

void get_line(char* filename) {

    char* text = NULL;
    char* temp;
    int size = INIT_SIZE;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    text = malloc(sizeof(char) * size);
    if (text == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    int c;
    while ((c = fgetc(file)) != EOF && c != '\n') {
        text[index++] = (char)c;

        if (index == size - 1) {
            size += INCREMENT_SIZE;
            temp = realloc(text, sizeof(char) * size);
            if (temp == NULL) {
                perror("Error reallocating memory");
                free(text);
                exit(EXIT_FAILURE);
            }
            text = temp;
        }
    }
    text[index] = '\0'; // Null-terminate the string

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

    return EXIT_SUCCESS;
}
