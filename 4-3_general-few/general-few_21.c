#include <stdio.h>
#include <stdlib.h>

struct Query {
    int *pages;
    int currentpage;
};

int main() {
    struct Query* new_query = malloc(sizeof(struct Query));
    int page_size = 4; // For example, set the size to 4

    new_query->pages = malloc(page_size * sizeof(int));

    // Perform your calculations here that determine the size needed for pages[]

    // Now you can access and use the pages array as needed
    for (int i = 0; i < page_size; i++) {
        new_query->pages[i] = i;
    }

    // Don't forget to free the dynamically allocated memory when you're done
    free(new_query->pages);
    free(new_query);

    return 0;
}
