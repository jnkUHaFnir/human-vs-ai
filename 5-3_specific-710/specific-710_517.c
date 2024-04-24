#include <stdio.h>
#include <stdlib.h>

char* readline(FILE *fp) {
    char* line = NULL;
    size_t len = 0;
    if(getline(&line, &len, fp) == -1) {
        free(line);
        return NULL; // End of file reached
    }
    return line;
}

int main(int argc, char *argv[]) {
    FILE *fp;

    /* Open the command for reading. */
    fp = popen("bash /home/ouhma/myscript.sh", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    /* Read the output a line at a time - output it. */
    char* line = NULL;
    while ((line = readline(fp)) != NULL) {
        printf("%s", line);
        free(line);
    }

    /* Close */
    pclose(fp);

    return 0;
}
