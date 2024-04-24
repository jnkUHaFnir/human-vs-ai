#include <stdio.h>
#include <stdlib.h>

struct Query {
    int * pages;     // Change to int pointer
    int currentpage;
};

int main() {
    struct Query *new_query = malloc(sizeof(struct Query));

    // Check if memory allocation was successful
    if (new_query == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Calculate the size needed for the pages[] array
    int size_needed = 4;

    // Dynamically allocate memory for the pages[] array with the desired size
    new_query->pages = malloc(size_needed * sizeof(int));

    // Check if memory allocation was successful
    if (new_query->pages == NULL) {
        printf("Memory allocation failed.\n");
        free(new_query);
        return 1;
    }

    // Now you can use new_query->pages as an array of size 4
    // Don't forget to free memory when you're done with it
    free(new_query->pages);
    free(new_query);

    return 0;
}
``` 

Remember to always free the dynamically allocated memory when you are finished using it to prevent memory leaks in your program.
