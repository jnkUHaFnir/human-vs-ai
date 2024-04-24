#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

char* readInputLine(FILE* stream) {
    char* line = NULL;
    char buffer[BUFFER_SIZE];
    size_t line_length = 0;
    
    while (fgets(buffer, BUFFER_SIZE, stream) != NULL) {
        size_t buffer_length = strlen(buffer);
        char* temp = realloc(line, line_length + buffer_length + 1);
        if (temp == NULL) {
            free(line);
            return NULL;
        }
        line = temp;
        
        strcpy(line + line_length, buffer);
        line_length += buffer_length;
        
        if (buffer[buffer_length - 1] == '\n') {  // Check if newline is reached
            break;
        }
    }
    
    return line;
}

int main() {
    // Reading from stdin
    printf("Enter a line of text: ");
    char* input1 = readInputLine(stdin);
    if (input1 != NULL) {
        printf("Line read from stdin: %s\n", input1);
        free(input1);
    } else {
        printf("Failed to read input from stdin.\n");
    }
    
    // Reading from a file
    FILE* file = fopen("input.txt", "r");
    if (file != NULL) {
        char* input2 = readInputLine(file);
        if (input2 != NULL) {
            printf("Line read from file: %s\n", input2);
            free(input2);
        } else {
            printf("Failed to read input from file.\n");
        }
        fclose(file);
    } else {
        printf("Failed to open file.\n");
    }

    return 0;
}
