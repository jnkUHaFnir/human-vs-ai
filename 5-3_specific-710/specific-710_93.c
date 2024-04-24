#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 10

char *readLine() {
    int bufferSize = INITIAL_BUFFER_SIZE;
    int position = 0;
    char *buffer = (char *)malloc(bufferSize * sizeof(char));
    int c;

    if (buffer == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    while (1) {
        c = getchar();

        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }

        position++;

        if (position >= bufferSize) {
            bufferSize += INITIAL_BUFFER_SIZE;
            buffer = (char *)realloc(buffer, bufferSize);

            if (buffer == NULL) {
                printf("Memory allocation error\n");
                exit(1);
            }
        }
    }
}

int main() {
    char *line;

    printf("Enter a line of text (press Enter to finish):\n");
    
    line = readLine();
    
    printf("You entered: %s\n", line);

    free(line);

    return 0;
}
