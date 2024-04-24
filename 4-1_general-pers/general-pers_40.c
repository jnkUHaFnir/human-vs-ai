#include <stdio.h>
#include <stdlib.h>

struct Query {
    int *pages;
    int currentpage;
};

int main() {
    struct Query new;
    int size = 4;
    
    new.pages = malloc(size * sizeof(int));
    
    // Check if memory allocation was successful
    if (new.pages == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Now you have an array of size "size" that you can use
    new.currentpage = 0;
    
    // Access and modify the array elements
    for (int i = 0; i < size; i++) {
        new.pages[i] = i;
    }
    
    // Don't forget to free the allocated memory when it's no longer needed
    free(new.pages);
    
    return 0;
}
