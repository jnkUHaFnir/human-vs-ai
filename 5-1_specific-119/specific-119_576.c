#include <stdio.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 100

int main() {
    FILE *fp;
    char username[MAX_USERNAME_LENGTH];

    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        return 1;
    }

    if (fgets(username, MAX_USERNAME_LENGTH, fp) != NULL) {
        // Remove the newline character at the end
        username[strcspn(username, "\n")] = 0;
        printf("Username: %s\n", username);
    } else {
        printf("Failed to read username\n");
    }

    pclose(fp);

    return 0;
}
