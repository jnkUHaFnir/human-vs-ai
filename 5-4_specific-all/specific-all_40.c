#include <stdio.h>
#include <stdlib.h>

struct Query {
    int *pages;
    int currentpage;
};

int main() {
    struct Query new;
    int size = 4; // Determine the size needed

    new.pages = malloc(sizeof(int) * size); // Dynamically allocate memory for pages[] array

    if (new.pages == NULL) {
        // Handle error, memory allocation failed
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Perform calculations

    new.currentpage = 0; // Set current page

    // Use new.pages as needed

    free(new.pages); // Don't forget to free the allocated memory when done

    return 0;
}
