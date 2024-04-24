#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 128

char* get_current_username() {
    char buf[MAX_BUF_SIZE];
    char *username = NULL;
    FILE *fp = popen("echo %username%", "r");

    if (fp == NULL) {
        printf("Error opening pipe!\n");
        return NULL;
    }

    if (fgets(buf, sizeof(buf), fp) != NULL) {
        // Remove the newline character at the end
        buf[strcspn(buf, "\n")] = 0;
        username = strdup(buf); // Allocate memory for the username
    }

    pclose(fp);
    return username;
}

int main() {
    char *username = get_current_username();

    if (username != NULL) {
        printf("Current username: %s\n", username);
        free(username); // Remember to free the memory after you are done using it
    } else {
        printf("Error getting username\n");
    }

    return 0;
}
