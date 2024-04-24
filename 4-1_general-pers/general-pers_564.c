#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    printf("Your name: \n");
    fgets(name, sizeof(name), stdin); // Using fgets to read input

    // Handling the case where the input buffer is not large enough
    if (strlen(name) == 99 && name[98] != '\n') {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {} // Clearing the input buffer
    } else {
        name[strcspn(name, "\n")] = '\0'; // Removing the newline character if present
    }

    printf("Name: %s\n", name);

    return 0;
}
