#include <stdlib.h>

struct Query {  
    int     currentpage;
    int     pages[]; // Flexible array member
};

int main() {
    // Determine the needed size of pages dynamically somehow
    int needed_pages_size = 4;
    
    // Allocate memory for the struct and its flexible array member
    struct Query *query = malloc(sizeof(struct Query) + sizeof(int) * needed_pages_size);
    
    if (!query) {
        // Handle memory allocation failure (e.g., by exiting)
        exit(EXIT_FAILURE);
    }
 
    // Now you can use query->pages as if it was an array of `needed_pages_size` integers
    // Initialize or set values as necessary
    for (int i = 0; i < needed_pages_size; ++i) {
        query->pages[i] = i; // Example initialization
    }
    
    // Example of accessing the flexible array values
    for (int i = 0; i < needed_pages_size; ++i) {
        printf("%d\n", query->pages[i]);
    }
    
    // Don't forget to free the allocated memory when you're done with it
    free(query);
    
    return 0;
}
