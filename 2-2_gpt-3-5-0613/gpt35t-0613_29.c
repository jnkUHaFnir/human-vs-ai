#include <stdio.h>
#include <stdlib.h>

// Define a macro to simplify the implementation of RAII
#define RAII(function) \
    __attribute__((cleanup(function)))

// Define a cleanup function to automatically close the file handle
void cleanup_file(FILE **fp) {
    if (*fp != NULL) {
        fclose(*fp);
        *fp = NULL; // Set the file handle to NULL after closing
    }
}

int main() {
    RAII(cleanup_file) FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) {
        perror("file error!");
        return EXIT_FAILURE;
    }
    
    if (other_condition) {
        perror("other error occurred!");
        return EXIT_FAILURE;
    }
    
    // file handling code here
    
    return EXIT_SUCCESS;
}
