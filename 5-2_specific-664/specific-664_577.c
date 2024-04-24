#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

int main() {
    FILE *fp;
    char path[MAX_BUFFER_SIZE];
    char username[MAX_BUFFER_SIZE];

    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        return 1;
    }

    // Read the output of the command into username string
    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        strcat(username, path);
    }

    pclose(fp);

    // Print the captured username
    printf("Username: %s\n", username);

    return 0;
}
