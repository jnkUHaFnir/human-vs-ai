#include <stdio.h>
#include <stdlib.h>

// Function to open a file and return a pointer to FILE
FILE* open_file(const char* filename, const char* mode) {
    FILE* fp = fopen(filename, mode);
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return fp;
}

// Function to close the file handle
void close_file(FILE* fp) {
    if (fp != NULL) {
        fclose(fp);
    }
}

int main() {
    FILE* fp = open_file("test.txt", "r");

    if (other_condition) {
        perror("other error occurred!");
        close_file(fp); // Ensure file handle is closed before returning
        return EXIT_FAILURE;
    }

    // Do operations with the file

    close_file(fp); // Close the file handle when done

    return EXIT_SUCCESS;
}
