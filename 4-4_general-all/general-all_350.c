#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *path_cmp1 = "/Users/john/";
char *path_cmp2 = "foo/bar.txt";

// Calculate the total length needed for the path
unsigned len = strlen(path_cmp1) + strlen(path_cmp2) + 1; // +1 for the null terminator

// Allocate memory for the complete path
char *path = (char *)malloc(len);
if (!path) {
    // Handle memory allocation failure
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
}

// Construct the path safely
snprintf(path, len, "%s%s", path_cmp1, path_cmp2);

// Use the constructed path

// Don't forget to free the memory when done
free(path);
path = NULL; // Optional: Set the pointer to NULL after freeing

