#include <stdio.h>
#include <stdlib.h>

// Custom function to close the file handle
void closeFile(FILE *fp) {
    if (fp != NULL) {
        fclose(fp);
        printf("File handle closed.\n");
    }
}

int main() {
    FILE* fp = fopen("test.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    if (other_condition) {
        perror("other error occurred!");
        closeFile(fp); // Call the cleanup function
        return EXIT_FAILURE;
    }

    // Process the file

    closeFile(fp); // Call the cleanup function before returning
    return EXIT_SUCCESS;
}
