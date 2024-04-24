#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define INIT_SIZE 50

void get_line (char* filename) {
    char* text;
    FILE* file = fopen(filename,"r");

    if (file == NULL) {
        printf("Failed to open file '%s'\n", filename);
        return;
    }

    int size = INIT_SIZE;
    int mem_idx = 0;
    int ch;
    text = malloc(sizeof(char) * size);

    while ((ch = fgetc(file)) != EOF && ch != '\n') {
        text[mem_idx++] = ch;
        if (mem_idx == size) {
            size *= 2;
            text = realloc(text, size * sizeof(char));
        }
    }

    // Check if EOF or \n was reached and break the loop
    if (ch == EOF && mem_idx == 0) {
        printf("No content in the file or reached the end of the file.\n");
    } else {
        // Add the null terminator at the end of the line
        text[mem_idx] = '\0';
        printf("The text was: %s\n", text);
    }

    fclose(file);
    free(text);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    get_line(argv[1]);

    return 0;
}
