#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char username[1024];
  
    fp = popen("echo %username%", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        exit(1);
    }

    while (fgets(username, sizeof(username), fp) != NULL) {
        // Remove the trailing newline character
        username[strcspn(username, "\n")] = 0;
    }

    pclose(fp);
    printf("Username: %s\n", username);

    return 0;
}
fp = popen("whoami", "r");
