struct Query {
    int *pages; // Use a pointer to an int
    int currentpage;
};
#include <stdio.h>
#include <stdlib.h>

// Your structure modified to use a pointer for pages
struct Query {
    int *pages;
    int currentpage;
};

int main() {
    // Step 1: Allocate memory for your structure
    struct Query *query = malloc(sizeof(struct Query));
    if (query == NULL) {
        fprintf(stderr, "Failed to allocate memory for struct Query.\n");
        return 1;
    }

    // Step 2: Calculate the size required for pages, let's say it needs to be 4
    int sizeNeeded = 4;

    // Step 3: Allocate memory for pages array within the structure
    query->pages = malloc(sizeNeeded * sizeof(int));
    if (query->pages == NULL) {
        fprintf(stderr, "Failed to allocate memory for pages.\n");
        free(query); // Don't forget to free the previously allocated memory
        return 1;
    }

    // Now you can use the pages array as needed

    // Example: Initializing pages
    for (int i = 0; i < sizeNeeded; ++i) {
        query->pages[i] = i + 1; // Just an example assignment
    }

    // Example usage: Printing the values
    for (int i = 0; i < sizeNeeded; ++i) {
        printf("Page %d: %d\n", i, query->pages[i]);
    }

    // Don't forget to free the memory when done
    free(query->pages); // Free the pages array first
    free(query);        // Then free the structure itself

    return 0;
}
