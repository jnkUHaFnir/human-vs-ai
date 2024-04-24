#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 256

int main() {
    char command[MAX_USERNAME_LENGTH + 10]; // maximum username length + "echo " and "%" characters
    char username[MAX_USERNAME_LENGTH];
    FILE* pipe;

    sprintf(command, "echo %%%s%%", "username"); // construct the command string

    pipe = popen(command, "r"); // execute the command and open a pipe to read its output
    if (!pipe) {
        perror("popen");
        exit(EXIT_FAILURE);
    }

    if (fgets(username, MAX_USERNAME_LENGTH, pipe)) { // read the output into the username string
        // remove the trailing newline character
        size_t length = strlen(username);
        if (length > 0 && username[length - 1] == '\n') {
            username[--length] = '\0';
        }

        printf("Username is: %s\n", username);
    } else {
        fprintf(stderr, "Failed to read username from command output\n");
    }

    pclose(pipe); // close the pipe

    return 0;
}
