#include <stdio.h>
#include <stdlib.h>

#define MAX_USERNAME_LENGTH 50

int main() {
    char username[MAX_USERNAME_LENGTH];
    FILE *fp;

    fp = popen("echo %username%", "r");
    
    if (fp == NULL) {
        perror("Error executing command");
        return 1;
    }

    if (fgets(username, MAX_USERNAME_LENGTH, fp) != NULL) {
        // Remove trailing newline character
        username[strcspn(username, "\n")] = '\0';
        
        printf("Username: %s\n", username);
    }
    
    pclose(fp);

    return 0;
}
