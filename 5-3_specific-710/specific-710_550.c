#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = popen("your_command", "w");

    if (fp == NULL) {
        perror("Error opening pipe");
        return 1;
    }

    // Send input to the command
    fprintf(fp, "input_data\n");
    fflush(fp); // Flush the output buffer

    // Read output from the command
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("Output: %s", buffer);
    }

    // Send more input or send "quit" to end the command

    pclose(fp); // Close the pipe
    return 0;
}
