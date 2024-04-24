#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Opening the file
    FILE *fp = fopen("file.txt", "r");
    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    char string[100]; // buffer to store lines from the file
    const char fetch[] = "learning"; // keyword to search for

    while (fgets(string, sizeof(string), fp)) {
        // Attempt to find 'fetch' keyword in the current line
        char *result = strstr(string, fetch);
        if (result) { // If found
            printf("Your result is: %s", result);
            // Removed the break if you want to continue searching throughout the file
        }
    }

    fclose(fp); // Don't forget to close the file
    return 0;
}
