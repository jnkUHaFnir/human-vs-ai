#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp = fopen("file.txt", "r");
    if(fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char string[100]; // Array to hold the line read from file
    char found[100]; // Array to hold the found word
    char *result;
    const char fetch[] = "learning"; // Ensure enough space for the word and null terminator

    while(fgets(string, 100, fp)) {
        if ((result = strstr(string, fetch)) != NULL) {
            strncpy(found, result, 99); // Copy the found word into 'found' array
            found[99] = '\0'; // Ensure null-termination
            printf("Found word: %s\n", found);
        }
    }

    fclose(fp);
    return 0;
}
