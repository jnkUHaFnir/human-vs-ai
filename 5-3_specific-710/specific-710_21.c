#include <stdio.h>
#include <stdlib.h>

struct Query {
    int *pages;
    int currentpage;
};

int main() {
    struct Query *newQuery = malloc(sizeof(struct Query)); // Allocate memory for struct Query

    int pageSize = 4; // Calculated size for pages[]

    newQuery->pages = malloc(pageSize * sizeof(int)); // Dynamically allocate memory for pages[] based on the calculated size

    newQuery->currentpage = 0; // Set initial value for currentpage

    // Access and modify pages array
    for (int i = 0; i < pageSize; i++) {
        newQuery->pages[i] = i * 10; // Just an example modification
    }

    // Print values in pages array
    for (int i = 0; i < pageSize; i++) {
        printf("pages[%d]: %d\n", i, newQuery->pages[i]);
    }

    // Don't forget to free the allocated memory when done
    free(newQuery->pages); // Free memory allocated for pages[]
    free(newQuery); // Free memory allocated for struct Query

    return 0;
}
