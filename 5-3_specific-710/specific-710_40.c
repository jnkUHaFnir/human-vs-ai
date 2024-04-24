#include <stdio.h>
#include <stdlib.h>

struct Query {
    int* pages;
    int currentpage;
};

int main() {
    struct Query new;
    int size = 4; // Set the size of the array

    new.pages = malloc(size * sizeof(int)); // Dynamically allocate memory for the array

    new.currentpage = 0; // Initialize currentpage

    // Use the pages array
    for (int i = 0; i < size; i++) {
        new.pages[i] = i; // Just an example, you can assign any values here
    }

    // Free the allocated memory when done
    free(new.pages);

    return 0;
}
