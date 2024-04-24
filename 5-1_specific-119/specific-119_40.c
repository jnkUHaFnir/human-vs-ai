#include <stdio.h>
#include <stdlib.h>

struct Query {
    int *pages;
    int currentpage;
};

int main() {
    struct Query *new_query = malloc(sizeof(struct Query));

    // Calculate the required size for pages[]
    int size = 4;

    // Allocate memory for pages[]
    new_query->pages = malloc(size * sizeof(int));

    // Update the size of pages[]
    new_query->currentpage = size;

    // You can now access and use new_query->pages as an array of size elements
    for (int i = 0; i < size; i++) {
        new_query->pages[i] = i; // Just an example
    }

    // Don't forget to free the allocated memory when done
    free(new_query->pages);
    free(new_query);

    return 0;
}
