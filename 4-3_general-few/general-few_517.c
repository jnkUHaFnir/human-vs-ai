#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer[BUFFER_SIZE];

    /* Open the command for reading. */
    fp = popen("bash /home/ouhma/myscript.sh", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    char *line = NULL;
    size_t line_size = 0;

    /* Read the output byte by byte until a newline is encountered */
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        size_t buffer_len = strlen(buffer);
        
        for (size_t i = 0; i < buffer_len; i++) {
            if (buffer[i] == '\n') {
                printf("%s", line); // Print the line
                free(line); // Free the dynamically allocated memory
                line = NULL;
                line_size = 0;
            } else {
                // Reallocate memory for the line
                line = realloc(line, line_size + 1);
                line[line_size] = buffer[i];
                line_size++;
            }
        }
    }

    /* Close */
    pclose(fp);
    
    if (line != NULL) {
        printf("%s", line); // Print the remaining line
        free(line); // Free the memory
    }

    return 0;
}
