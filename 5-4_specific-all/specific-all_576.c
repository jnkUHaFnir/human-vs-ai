#include <stdio.h>
#include <stdlib.h>

#define MAX_USERNAME_LENGTH 50

char* get_username() {
    FILE* fp;
    char buffer[MAX_USERNAME_LENGTH];
    char* username = NULL;

    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        return NULL;
    }

    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Remove newline character if present
        char* newline = strchr(buffer, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }

        username = (char*)malloc(strlen(buffer) + 1);
        if (username != NULL) {
            strcpy(username, buffer);
        }
    }

    pclose(fp);

    return username;
}

int main() {
    char* username = get_username();

    if (username != NULL) {
        printf("Username: %s\n", username);
        free(username);
    } else {
        printf("Failed to get username\n");
    }

    return 0;
}
