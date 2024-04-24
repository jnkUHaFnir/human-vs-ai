#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 50
#define BUFFER_INCREMENT 10

void get_line(char* filename) {
    char* text = NULL;
    int text_size = INIT_SIZE; // Initial buffer size
    int text_len = 0;
    
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    text = malloc(sizeof(char) * text_size);
    if (text == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    while (fgets(text + text_len, text_size - text_len, file) != NULL) {
        text_len += strlen(text + text_len); // Calculate the current length of text in the buffer

        if (text[text_len - 1] == '\n') { // Line read successfully
            break;
        }

        char* new_text = realloc(text, text_size + BUFFER_INCREMENT); // Resize the buffer
        if (new_text == NULL) {
            printf("Memory reallocation failed.\n");
            free(text);
            return;
        }
        
        text = new_text;
        text_size += BUFFER_INCREMENT;
    }

    printf("The text was %s\n", text);

    free(text);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    get_line(argv[1]);
    return 0;
}
