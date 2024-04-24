#include <stdio.h>

int main()
{
    FILE *fp;
    char command[50];
    char buffer[100];

    // Open pipe to command in read mode
    fp = popen("your_command", "r");

    if (fp == NULL) {
        printf("Failed to open pipe.\n");
        return 1;
    }

    // Continuously read the command output until it is finished
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("Output: %s", buffer);
    }

    // Close the pipe
    pclose(fp);

    return 0;
}
