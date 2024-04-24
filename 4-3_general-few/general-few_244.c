#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 50

void get_line(const char* filename) {
    char* text = NULL;
    size_t size = INIT_SIZE;
    size_t index = 0;
    int c;
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    text = malloc(sizeof(char) * size);

    if (text == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    while ((c = fgetc(file)) != '\n' && c != EOF) {
        text[index++] = c;
        
        if (index == size - 1) { // Need more space
            size *= 2;
            char* tmp = realloc(text, size);
        
            if (tmp == NULL) {
                printf("Memory reallocation error.\n");
                free(text);
                exit(1);
            }
            
            text = tmp;
        }
    }

    text[index] = '\0'; // Null-terminate the string
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
