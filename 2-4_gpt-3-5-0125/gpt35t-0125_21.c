#include <stdio.h>
#include <stdlib.h>

struct Query {  
    int* pages;
    int currentpage;
};

int main() {
    struct Query *new_query = malloc(sizeof(struct Query));

    // Perform your calculations to determine the size needed for pages[]
    int size_needed = 4;

    // Dynamically allocate memory for pages[] based on the size needed
    new_query->pages = malloc(size_needed * sizeof(int));

    // You can now use new_query->pages as an array of size 4
    // Remember to free the memory when you are done using it
    free(new_query->pages);
    free(new_query);

    return 0;
}
