#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[1024];

    // Open a pipe to run the custom command
    fp = popen("custom_command", "w");

    if (fp == NULL) {
        printf("Error: Unable to open pipe");
        return 1;
    }

    // Write input to the command
    fprintf(fp, "input1\n");
    fflush(fp);

    // Read output from the command
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    // Write more input to the command
    fprintf(fp, "input2\n");
    fflush(fp);

    // Close the pipe
    pclose(fp);

    return 0;
}
