#include <stdio.h>
#include <stdlib.h> // Required for malloc and free functions

struct patron {
   char last_name[30];
   char first_name[30];
};

struct theatre_seating {
    struct patron **seating;
};

void init(int elem, struct theatre_seating *t);

int main() {
    struct theatre_seating theatre_seating;
    int elem = 2;
    
    init(elem, &theatre_seating);
    
    // Example of how to access patron data
    strcpy(theatre_seating.seating[0]->first_name, "John");
    strcpy(theatre_seating.seating[0]->last_name, "Doe");
    strcpy(theatre_seating.seating[1]->first_name, "Jane");
    strcpy(theatre_seating.seating[1]->last_name, "Smith");
    
    printf("Seating 0: %s %s\n", theatre_seating.seating[0]->first_name, theatre_seating.seating[0]->last_name);
    printf("Seating 1: %s %s\n", theatre_seating.seating[1]->first_name, theatre_seating.seating[1]->last_name);

    // Don't forget to release the allocated memory
    for (int i = 0; i < elem; ++i) {
        free(theatre_seating.seating[i]);
    }
    free(theatre_seating.seating);
    
    return 0;
}

void init(int elem, struct theatre_seating *t) {
    // Allocate memory for an array of struct patron pointers
    t->seating = malloc(elem * sizeof(struct patron*));
    if (!t->seating) {
        // Handle the error if memory allocation fails
        perror("Memory allocation for seating failed");
        exit(EXIT_FAILURE);
    }
    
    // Allocate memory for each struct patron and assign to the array
    for (int i = 0; i < elem; ++i) {
        t->seating[i] = malloc(sizeof(struct patron));
        if (!t->seating[i]) {
            // Handle the error if memory allocation fails
            perror("Memory allocation for a single patron failed");
            exit(EXIT_FAILURE);
        }
    }
}
