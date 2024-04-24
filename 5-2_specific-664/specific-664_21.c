#include <stdio.h>
#include <stdlib.h>

struct Query {
    int* pages;
    int currentpage;
};

int main() {
    struct Query* new_query = malloc(sizeof(struct Query));
    if (new_query == NULL) {
        // Handle error
        return 1;
    }

    int array_size = 4; // Size of pages array needed
    new_query->pages = malloc(array_size * sizeof(int));
    if (new_query->pages == NULL) {
        // Handle error
        free(new_query);
        return 1;
    }

    new_query->currentpage = 0;

    // Now you can access and modify elements of the pages array
    for (int i = 0; i < array_size; i++) {
        new_query->pages[i] = i * 10; // Just an example calculation
    }

    // Don't forget to free the memory when you're done
    free(new_query->pages);
    free(new_query);

    return 0;
}
