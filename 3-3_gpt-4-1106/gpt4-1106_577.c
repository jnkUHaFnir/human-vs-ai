#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fp;
    char result[128]; // Adjust the size as needed
    char *username = NULL;

    // Open the command for reading
#ifdef _WIN32 // Check if the OS is Windows
    fp = _popen("echo %username%", "r");
#else
    // Alternatively for Unix-based systems (e.g., Linux, macOS)
    fp = popen("echo $USER", "r");
#endif

    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }

    // Read the output a line at a time
    if (fgets(result, sizeof(result), fp) != NULL) {
        // Strip the trailing newline character
        size_t len = strlen(result);
        if (len > 0 && result[len - 1] == '\n') {
            result[len - 1] = '\0';
        }
        username = result;
    }

    // Close the command stream
#ifdef _WIN32
    _pclose(fp);
#else
    pclose(fp);
#endif

    // Use the username string
    if (username) {
        printf("The username is: %s\n", username);
    } else {
        printf("Failed to retrieve the username.\n");
    }

    return 0;
}
