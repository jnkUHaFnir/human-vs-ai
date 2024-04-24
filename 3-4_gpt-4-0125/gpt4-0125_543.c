#include <stdio.h>
#include <stdlib.h> // For malloc

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

    // Example usage
    // After initializing, you can access and set the values
    // Be cautious, always check if allocation was successful before accessing
    if (theatre_seating.seating != NULL && theatre_seating.seating[0] != NULL) {
        // Set values for first patron
        snprintf(theatre_seating.seating[0]->first_name, 30, "John");
        snprintf(theatre_seating.seating[0]->last_name, 30, "Doe");

        // Set values for second patron
        snprintf(theatre_seating.seating[1]->first_name, 30, "Jane");
        snprintf(theatre_seating.seating[1]->last_name, 30, "Smith");
    }

    // Always remember to free the allocated memory to avoid memory leaks
    for (int i = 0; i < elem; ++i) {
        free(theatre_seating.seating[i]); // Free each patron
    }
    free(theatre_seating.seating); // Free the array of pointers

    return 0;
}

void init(int elem, struct theatre_seating *t) {
    // Allocate memory for an array of pointers to struct patron
    t->seating = (struct patron**)malloc(elem * sizeof(struct patron*));

    if (t->seating == NULL) {
        // Handle malloc failure (optional but recommended)
        // Example: print an error message, exit the function or program, etc.
        fprintf(stderr, "Memory allocation for seating failed\n");
        return;
    }

    // Allocate memory for each patron
    for (int i = 0; i < elem; i++) {
        t->seating[i] = (struct patron*)malloc(sizeof(struct patron));

        if (t->seating[i] == NULL) {
            // Handle malloc failure for individual patron (optional but recommended)
            // Example: print an error message, handle previously allocated memory to avoid leaks, etc.
            fprintf(stderr, "Memory allocation for patron %d failed\n", i);

            // Cleanup previously allocated memory to avoid leaks
            for (int j = 0; j < i; j++) {
                free(t->seating[j]); // Free each successfully allocated patron
            }
            free(t->seating); // Free the array of pointers
            t->seating = NULL; // Ensure the pointer is null after freeing to avoid use-after-free
            return;
        }
    }
}
