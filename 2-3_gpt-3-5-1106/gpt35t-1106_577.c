#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char path[1035];

    // Open the command for reading
    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    // Read the output a line at a time - assuming only one line of output
    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        // Do something with the output, for example printing it to the console
        printf("Logged in as: %s", path);
    }

    // close
    pclose(fp);

    return 0;
}
