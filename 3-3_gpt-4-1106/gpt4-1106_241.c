#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 50
#define CHUNK_SIZE 10 // Read in smaller chunks for demonstration

// Function prototypes
void get_line(const char* filename);

int main(int argc, char *argv[]) {
    if(argc < 2) {
       fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
       return 1;
    }
    get_line(argv[1]);
    return 0;
}

void get_line(const char* filename) {
    char *text;
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int size = INIT_SIZE;
    int index = 0;
    char* buffer = malloc(size);
    if (!buffer) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer + index, CHUNK_SIZE, file)) {
        // Check if we've reached the end of the line or EOF
        char *newlinePtr = strchr(buffer + index, '\n');
        if (newlinePtr != NULL) {
            // Set the newline to null-terminator if found
            *newlinePtr = '\0';
            break;
        }

        // Check how many characters were read (excluding null-terminator)
        int charsRead = strlen(buffer + index);

        // Move index to the end of string
        index += charsRead;

        // Check if we need more space
        if (index + CHUNK_SIZE >= size) {
            size *= 2; // Double the size
            char *newBuffer = realloc(buffer, size);
            if (!newBuffer) {
                perror("Memory reallocation failed");
                free(buffer);
                fclose(file);
                exit(EXIT_FAILURE);
            }
            buffer = newBuffer;
        }
    }

    printf("The text was: %s\n", buffer);

    free(buffer);
    fclose(file);
}
