#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[1024];

    fp = popen("your_custom_command", "w");

    if (fp == NULL) {
        perror("Error opening pipe!");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Enter input: ");
        fgets(buffer, sizeof(buffer), stdin);

        // Input validation or processing can be done here

        fprintf(fp, "%s", buffer);
        
        if (strcmp(buffer, "quit\n") == 0) {
            break;
        }
    }

    pclose(fp);

    return 0;
}
