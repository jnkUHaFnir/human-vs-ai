#include <stdio.h>
#include <stdlib.h>

struct Query {
    int *pages;
    int currentpage;
};

int main() {
    struct Query new;
    int size = 4; // Set size to 4

    new.pages = malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (new.pages == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Now you can access and modify elements of pages[]
    for (int i = 0; i < size; i++) {
        new.pages[i] = i * 10; // Just an example
    }

    // Remember to free the allocated memory when you are done
    free(new.pages);

    return 0;
}
