#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUF_SIZE 1024

// Function to read a potentially very long line of output
char *read_long_line(FILE *fp) {
    char *buffer = NULL;
    char *temp = NULL;
    size_t bufsize = 0;
    size_t bufferlen = 0;
    size_t chunklen = INITIAL_BUF_SIZE; // Initial chunk size
    size_t readlen;
    char chunk[INITIAL_BUF_SIZE]; // Temp buffer for each chunk read

    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        readlen = strlen(chunk);
        if (bufsize - bufferlen <= readlen) { // Need to expand buffer
            bufsize += chunklen; // Increase the buffer size in chunklen increments
            temp = realloc(buffer, bufsize);
            if (!temp) {
                free(buffer);
                fprintf(stderr, "Failed to allocate memory\n");
                return NULL;
            }
            buffer = temp;
        }
        strcpy(buffer + bufferlen, chunk); // Copy new chunk into buffer
        bufferlen += readlen;
        if (chunk[readlen - 1] == '\n') {
            break; // If last read chunk contains a newline, we've read the whole line
        }
    }

    return buffer; // Caller is responsible for freeing this memory
}

int main(int argc, char *argv[]) {

    FILE *fp;
    char *output;

    /* Open the command for reading. */
    fp = popen("bash /home/ouhma/myscript.sh", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        exit(1);
    }

    // Read the output a line at a time - output it.
    while ((output = read_long_line(fp)) != NULL) {
        printf("%s", output);
        free(output); // Free the dynamically allocated memory
    }

    // Close the pipe
    pclose(fp);

    return 0;
}
