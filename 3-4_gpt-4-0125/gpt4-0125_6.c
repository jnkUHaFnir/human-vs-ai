#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Assuming `read_line` function prototype as follows (or adjust as needed):
// char* read_line(FILE* stream);

int main() {
    FILE *fin = fopen("file1.txt", "r");

    char *url = NULL; // Initialize url to NULL
    char *line;
    if (fin) {
        while ((line = read_line(fin)) != NULL) {
            char *found = strstr(line, "url=");
            if (found != NULL) {
                free(url); // Free previous url memory before assignment if non-NULL
                url = strdup(found); // Make a copy of the part of line starting with "url="
                if (url) {
                    fprintf(stdout, "%s\n", url);
                } else {
                    fprintf(stderr, "Failed to allocate memory for url copy\n");
                    // Handle memory allocation failure (e.g., break, free resources, exit)
                    free(line);
                    fclose(fin);
                    return 1;
                }
            }
            free(line);
        }
        fclose(fin);
    }

    if (url) {
        printf("line is:%s\n", url); // Print the copied URL
        free(url); // Don't forget to free the copied URL to avoid memory leak
    } else {
        printf("No URL found.\n");
    }

    return 0;
}
