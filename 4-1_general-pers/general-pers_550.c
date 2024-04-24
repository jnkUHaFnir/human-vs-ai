#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char command[100];
    char buffer[1024];

    while (1) {
        printf("Enter a command (or type 'quit' to exit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        fp = popen(command, "r");
        if (fp == NULL) {
            fprintf(stderr, "Failed to run command\n");
            exit(1);
        }

        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("%s", buffer);
        }

        pclose(fp);
    }

    return 0;
}
