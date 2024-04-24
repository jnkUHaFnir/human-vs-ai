#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char path[1035];
    char username[1000];

    /* Open the command for reading. */
    fp = popen("echo %username%", "r");

    if (fp == NULL) {
        printf("Failed to run command\n");
        return 1;
    }

    /* Read the output a line at a time - output it. */
    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        strcat(username, path);
    }

    /* close */
    pclose(fp);

    // Remove the newline character from the username
    username[strcspn(username, "\n")] = 0;

    printf("The username is: %s\n", username);

    return 0;
}
