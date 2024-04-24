#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 50

void get_line(char* filename) {
    char* text;
    int capacity = INIT_SIZE; // initial capacity
    int size = 0; // current size
    char* temp;

    FILE* file = fopen(filename, "r");

    text = malloc(sizeof(char) * capacity);

    if (text == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    while (fgets(text + size, capacity - size, file) != NULL) {
        size += strlen(text + size);

        if (text[size - 1] == '\n') {
            text[size - 1] = '\0'; // remove '\n' from the end of the line
            break; // exit loop when a full line is read
        }

        // resize the buffer if it is full
        if (size == capacity - 1) {
            capacity *= 2;
            temp = realloc(text, sizeof(char) * capacity);

            if (temp == NULL) {
                printf("Memory reallocation failed\n");
                free(text);
                exit(1);
            }

            text = temp;
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
