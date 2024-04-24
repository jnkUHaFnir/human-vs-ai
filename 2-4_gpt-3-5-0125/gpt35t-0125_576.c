#include <stdio.h>

int main() {
    FILE *fp;
    char username[50];

    // Open the command for reading
    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        return 1;
    }

    // Read the output into the username array
    fgets(username, sizeof(username)-1, fp);

    // Close the file pointer
    pclose(fp);

    // Print the username
    printf("Username: %s", username);

    return 0;
}
