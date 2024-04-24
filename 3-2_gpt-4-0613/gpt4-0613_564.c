#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int main() {
    char* name = malloc(MAX_LEN);
    if (name == NULL) {
        printf("Failed to allocate memory.");
        return -1;
    }

    printf("Your name: \n");
    fgets(name, MAX_LEN, stdin);

    // Removing newline character added by fgets
    name[strcspn(name, "\n")] = 0;

    printf("Name: %s\n", name);

    // Reduce the allocated memory to the actual size of the string
    name = realloc(name, strlen(name) + 1);

    // ... use the name here ...

    // Don't forget to free your allocated memory
    free(name);

    return 0;
}
