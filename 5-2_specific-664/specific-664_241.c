#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 50
#define GROWTH_FACTOR 2

void get_line(char* filename) {
    char* text = NULL;
    size_t size = INIT_SIZE;
    size_t index = 0;
    int c;
    
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return;
    }

    text = malloc(sizeof(char) * size);
    if (text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return;
    }

    while ((c = fgetc(file)) != EOF && c != '\n') {
        text[index++] = (char) c;
        
        // If we have reached the current allocated size, reallocate more memory
        if (index == size - 1) {
            size *= GROWTH_FACTOR;
            char* new_text = realloc(text, sizeof(char) * size);
            if (new_text == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                free(text);
                fclose(file);
                return;
            }
            text = new_text;
        }
    }
    
    text[index] = '\0'; // Null-terminate the string
    printf("The text was: %s\n", text);

    free(text);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    get_line(argv[1]);

    return 0;
}
