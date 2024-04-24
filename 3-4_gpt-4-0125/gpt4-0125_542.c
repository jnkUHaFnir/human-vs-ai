#include <stdio.h>
#include <stdlib.h> // For malloc and free

struct patron {
   char last_name[30];
   char first_name[30];
};

struct theatre_seating {
    struct patron **seating;
};

void init(int elem, struct theatre_seating *t);
void deinit(struct theatre_seating *t); // Function to free allocated memory

int main() {
    struct theatre_seating theatre_seating;

    int elem = 2;

    init(elem, &theatre_seating);

    // Example of how to access and set data for the first patron
    strcpy(theatre_seating.seating[0]->first_name, "John");
    strcpy(theatre_seating.seating[0]->last_name, "Doe");

    // Example of how to access and set data for the second patron
    strcpy(theatre_seating.seating[1]->first_name, "Jane");
    strcpy(theatre_seating.seating[1]->last_name, "Smith");

    // Cleanup
    deinit(&theatre_seating);

    return 0;
}

void init(int elem, struct theatre_seating *t) {
    // Allocate memory for an array of patron pointers
    t->seating = malloc(elem * sizeof(struct patron*));
    if (t->seating == NULL) {
        // Handle memory allocation failure
        return;
    }

    for(int i = 0; i < elem; i++) {
        // For each patron, allocate memory for a patron structure
        t->seating[i] = malloc(sizeof(struct patron));
        if (t->seating[i] == NULL) {
            // Handle memory allocation failure
            // Also, cleanup previously allocated memory here if needed
            return;
        }
    }
}

void deinit(struct theatre_seating *t) {
    // Free memory for each patron structure
    for(int i = 0; t->seating[i] != NULL; i++) {
        free(t->seating[i]);
    }
    // Free the array of pointers
    free(t->seating);
}
