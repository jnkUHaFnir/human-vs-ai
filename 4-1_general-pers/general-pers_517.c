#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {

    FILE *fp;
    char *line = NULL;
    size_t buf_size = 0;

    /* Open the command for reading. */
    fp = popen("bash /home/ouhma/myscript.sh", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    /* Read the output dynamically line by line - output it. */
    while (getline(&line, &buf_size, fp) != -1) {
        printf("%s", line);
    }

    if (line) {
        free(line);
    }

    /* close */
    pclose(fp);

    return 0;
}
