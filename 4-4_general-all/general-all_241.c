#include <stdio.h>
#include <stdlib.h>

void get_line(char *filename) {
    char *text = NULL; 
    size_t size = 0;
    size_t length = 0;
    
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int c;
    while ((c = fgetc(file)) != '\n' && c != EOF) {
        if (length + 1 >= size) {
            size = (size == 0) ? 1 : size * 2; // Double the size
            text = realloc(text, size);
            if (text == NULL) {
                fclose(file);
                free(text);
                perror("Error allocating memory");
                exit(1);
            }
        }
        text[length++] = (char)c;
    }
    
    text[length] = '\0'; // Null-terminate the string
    
    printf("The text was: %s\n", text);

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
