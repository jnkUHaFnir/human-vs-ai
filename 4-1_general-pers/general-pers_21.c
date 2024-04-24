#include <stdio.h>
#include <stdlib.h>

struct Query {
    int *pages;
    int currentpage;
};

int main() {
    // Create an instance of the structure
    struct Query *new_query = malloc(sizeof(struct Query));

    // Perform calculations to determine the size needed for pages[]
    int size_needed = 4;

    // Dynamically allocate memory for pages[]
    new_query->pages = malloc(size_needed * sizeof(int));

    // Now you can use new_query as needed

    // Don't forget to free the allocated memory when you're done
    free(new_query->pages);
    free(new_query);

    return 0;
}
