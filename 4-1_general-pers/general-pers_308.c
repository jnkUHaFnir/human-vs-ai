#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE *fp = fopen("file.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char string[MAX_LINE_LENGTH];
    char found[MAX_LINE_LENGTH];
    const char fetch[] = "learning";
  
    while (fgets(string, MAX_LINE_LENGTH, fp)) {
        // Remove the newline character from the string if it exists
        size_t len = strlen(string);
        if (string[len - 1] == '\n') {
            string[len - 1] = '\0';
        }

        strncpy(found, string, MAX_LINE_LENGTH); // Use strncpy to enforce boundary limits
        found[MAX_LINE_LENGTH - 1] = '\0'; // Ensure null-termination
        printf("Your input: %s\n", found);

        char *result = strstr(found, fetch);
        if (result != NULL) {
            printf("Found '%s' at position %ld\n", fetch, result - found);
            // You can break here if you only want to find the first occurrence
        }
    }

    fclose(fp);

    return 0;
}
