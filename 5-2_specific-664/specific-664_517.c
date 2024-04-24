#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *fp;
    char *line = NULL;
    size_t line_size = 0;
    size_t line_capacity = 0;

    /* Open the command for reading. */
    fp = popen("bash /home/ouhma/myscript.sh", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    /* Read the output dynamically. */
    while (fgets(line + line_size, CHUNK_SIZE, fp) != NULL) {
        line_size += strlen(line + line_size);
        if (line_size + CHUNK_SIZE > line_capacity) {
            line_capacity += CHUNK_SIZE;
            line = realloc(line, line_capacity);
            if (!line) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
        }
    }

    /* Print the output. */
    printf("%s", line);

    /* Cleanup */
    free(line);
    pclose(fp);

    return 0;
}
