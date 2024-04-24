#include <stdio.h>
#include <stdlib.h>

struct Query {  
    int* pages;
    int currentpage;
};

int main() {
    struct Query* new_query = malloc(sizeof(struct Query));

    int calculated_size = 4; // Calculate the size needed for pages[]

    new_query->pages = malloc(calculated_size * sizeof(int));
    if (new_query->pages == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // You can now freely use new_query->pages like a normal array
    for (int i = 0; i < calculated_size; i++) {
        new_query->pages[i] = i * 10;
    }

    // Don't forget to free the memory when you're done using it
    free(new_query->pages);
    free(new_query);

    return 0;
}
