#include <stdlib.h>

struct Query {
    int currentpage;
    int pages[]; // Flexible array member
};

int main() {
    size_t num_pages = 4; // Set the size you need for pages[]

    // Allocate memory for the struct Query along with the array
    struct Query* new_query = malloc(sizeof(struct Query) + num_pages * sizeof(int));
    
    if (new_query == NULL) {
        // Handle memory allocation failure
        return 1;
    }
    
    // Now you can access and modify the 'pages' array as needed
    for (size_t i = 0; i < num_pages; i++) {
        new_query->pages[i] = i;
    }
    
    // Set the current page
    new_query->currentpage = 0;

    // Don't forget to free the allocated memory when you're done with it
    free(new_query);
    
    return 0;
}
