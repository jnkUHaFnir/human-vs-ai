#include <stdio.h>
#include <stdlib.h>

struct Query {
    int *pages;
    int currentpage;
};

int main() {
    struct Query *newQuery = malloc(sizeof(struct Query));

    if (newQuery == NULL) {
        printf("Memory allocation failed. Exiting...");
        return 1;
    }

    // Perform calculations to determine the size needed for pages[]
    int sizeNeeded = 4;

    newQuery->pages = malloc(sizeNeeded * sizeof(int));

    if (newQuery->pages == NULL) {
        printf("Memory allocation failed for pages. Exiting...");
        free(newQuery);
        return 1;
    }

    // Initialize pages[]
    for (int i = 0; i < sizeNeeded; i++) {
        newQuery->pages[i] = i + 1; // Example initialization
    }

    newQuery->currentpage = 1; // Just an example value

    // Use the newQuery struct and its pages[] array here...

    // Don't forget to free the allocated memory
    free(newQuery->pages);
    free(newQuery);

    return 0;
}
