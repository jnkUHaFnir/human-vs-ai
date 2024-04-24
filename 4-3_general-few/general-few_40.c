#include <stdio.h>
#include <stdlib.h>

struct Query {
    int* pages;
    int currentpage;
};

int main() {
    struct Query* newQuery = malloc(sizeof(struct Query));
    
    // Perform calculations to determine the size needed for pages
    int sizeNeeded = 4;
    
    // Dynamically allocate memory for the pages array
    newQuery->pages = malloc(sizeNeeded * sizeof(int));
    
    // You can now use newQuery->pages as an array of size 4
    newQuery->pages[0] = 10;
    newQuery->pages[1] = 20;
    newQuery->pages[2] = 30;
    newQuery->pages[3] = 40;
    
    // Don't forget to free the memory when you're done using it
    free(newQuery->pages);
    free(newQuery);
    
    return 0;
}
