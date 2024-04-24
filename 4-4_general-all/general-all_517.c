#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char *path = NULL;
    size_t path_size = 0;

    /* Open the command for reading. */
    fp = popen("bash /home/ouhma/myscript.sh", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    /* Read the output dynamically. */
    char buffer[1024];
    size_t len;
    while ((len = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        path = realloc(path, path_size + len + 1);
        if (path == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(1);
        }
        memcpy(path + path_size, buffer, len);
        path_size += len;
    }

    path[path_size] = '\0';  // Null-terminate the string

    /* Output the entire read line. */
    printf("%s", path);

    /* Free dynamically allocated memory and close the file pointer. */
    free(path);
    pclose(fp);

    return 0;
}
