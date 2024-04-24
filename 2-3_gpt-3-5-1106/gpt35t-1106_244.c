#include "stdio.h"
#include "stdlib.h"

#define INIT_SIZE 50
#define INCREMENT 10 // The amount by which the array size will be increased

void get_line (char* filename) {
    char* text;
    int size = INIT_SIZE;
    int index = 0;
    
    FILE* file = fopen(filename,"r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    text = malloc(sizeof(char) * size);
    
    if (text == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    
    int c;
    while ((c = fgetc(file)) != EOF && c != '\n') {
        text[index++] = c;
        if (index == size) {
            size += INCREMENT;
            char* temp = realloc(text, size);
            if (temp == NULL) {
                perror("Error reallocating memory");
                exit(EXIT_FAILURE);
            }
            text = temp;
        }
    }
    
    text[index] = '\0'; // Add null terminator at the end of the text
    
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
