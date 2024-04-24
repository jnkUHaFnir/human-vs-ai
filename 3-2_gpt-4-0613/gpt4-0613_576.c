#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char output[100];
    FILE *fp;

    // Run system command and open it's output
    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        exit(1);
    }

    // Read the output of the command
    while (fgets(output, sizeof(output)-1, fp) != NULL) {
        printf("Output is: %s", output);
    }

    // close the pipe
    pclose(fp);

    return 0;
}
