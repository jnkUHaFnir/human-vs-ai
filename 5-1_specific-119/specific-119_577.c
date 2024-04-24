#include <stdio.h>
#include <stdlib.h>

#define MAX_USERNAME_LENGTH 100

char* get_username() {
    FILE* pipe = popen("echo %username%", "r");
    if (!pipe) {
        return NULL;
    }

    char username[MAX_USERNAME_LENGTH];
    if (!fgets(username, sizeof(username), pipe)) {
        pclose(pipe);
        return NULL;
    }

    pclose(pipe);

    // Remove the newline character from the end of the username
    username[strcspn(username, "\n")] = '\0';

    // Dynamically allocate memory to return the username
    char* result = (char*)malloc(strlen(username) + 1);
    if (!result) {
        return NULL;
    }

    strcpy(result, username);
    return result;
}

int main() {
    char* username = get_username();
    if (username) {
        printf("Username: %s\n", username);
        free(username);
    } else {
        printf("Failed to retrieve username\n");
    }

    return 0;
}
