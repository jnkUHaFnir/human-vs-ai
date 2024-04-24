#include <stdio.h>
#include <stdlib.h>

struct Query {
    int *pages; // Change to int pointer
    int currentpage;
};

int main() {
    struct Query *new_query = malloc(sizeof(struct Query));
    if (new_query == NULL) {
        // Handle malloc failure
        printf("Memory allocation failed");
        return 1;
    }
    
    int size_needed = 4; // Size of pages array needed
    
    new_query->pages = malloc(size_needed * sizeof(int));
    if (new_query->pages == NULL) {
        // Handle malloc failure
        printf("Memory allocation failed");
        free(new_query);
        return 1;
    }
    
    new_query->currentpage = 0; // Initialize current page
    
    // Use new_query->pages as needed
    
    // Don't forget to free memory when done
    free(new_query->pages);
    free(new_query);
    
    return 0;
}
