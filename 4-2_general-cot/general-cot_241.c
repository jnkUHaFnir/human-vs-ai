#include <stdio.h>
#include <stdlib.h>

void get_line(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    char* text = NULL;
    int text_size = 0;
    int max_size = 0;
    char c;

    while ((c = fgetc(file)) != EOF && c != '\n') {
        if (text_size == max_size) {
            // Increase the size of the text buffer
            max_size += 50;  // Increase buffer by 50 characters
            char* temp = realloc(text, max_size);
            if (temp == NULL) {
                // Handle memory reallocation failure
                printf("Error reallocating memory\n");
                free(text);
                return;
            }
            text = temp;
        }
        text[text_size++] = c;
    }

    text = realloc(text, text_size + 1); // Resize to actual size plus one for null terminator
    text[text_size] = '\0'; // Null-terminate the string

    printf("The text was: %s\n", text);

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
