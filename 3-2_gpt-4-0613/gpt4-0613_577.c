#include <stdio.h>
#include <stdlib.h>

int main() {
    char username[128];
    FILE *fp;

    /* Open the command for reading. */
    fp = _popen("echo %username%", "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }

    /* Read the output a line at a time - output it. */
    while (fgets(username, sizeof(username)-1, fp) != NULL) {
        printf("%s", username);
    }

    /* close */
    _pclose(fp);

    return 0;
}
