#include <stdio.h>
#include <stdlib.h>

int main() {
    char *name = malloc(sizeof(char) * 256); 
    if (name == NULL) {
        // In case malloc fails
        perror("Unable to allocate memory");
        return 1;
    }

    printf("What is your name? ");

    // Use scanf to read input including spaces up until a newline character
    scanf("%255[^\n]", name); // 255 to make sure there's room for the null terminator

    printf("Hello %s. Nice to meet you.\n", name);

    // Free the allocated memory
    free(name);

    return 0;
}
