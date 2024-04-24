#include <stdio.h>
#include <stdlib.h>

struct book {
    char name[20];
};

int main() {
    struct book buk[10];
    int i;
    char tempBuffer[100]; // Temporary buffer to clear the input buffer

    for(i=0; i<3; i++) {
        printf("Enter name of book %d: ", i+1);
        // Clear the input buffer before each scanf call
        while ((getchar()) != '\n'); // Clear the input buffer

        if (fgets(buk[i].name, sizeof(buk[i].name), stdin) != NULL) {
            // Remove the trailing newline character if present
            char *newlinePos = strchr(buk[i].name, '\n');
            if (newlinePos != NULL) {
                *newlinePos = '\0';
            }
        } else {
            printf("Error reading input.\n");
            exit(EXIT_FAILURE);
        }
    }

    for(i=0; i<3; i++) {
        printf("Book %d: %s\n", i+1, buk[i].name);
    }

    return 0;
}
