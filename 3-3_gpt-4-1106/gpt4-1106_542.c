#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    // Example of usage
    printf("First Patron's first name: %s\n", theatre_seating.seating[0]->first_name);
    printf("Second Patron's first name: %s\n", theatre_seating.seating[1]->first_name);

    // Always free memory when done
    for (int i = 0; i < elem; ++i) {
        free(theatre_seating.seating[i]); // Frees individual patron
    }
    free(theatre_seating.seating); // Frees array of pointers

    return 0;
}

void init(int elem, struct theatre_seating *t) {
    // Allocate memory for an array of patron pointers
    t->seating = malloc(elem * sizeof(struct patron *));
    if (t->seating == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Set initial value for each pointer in the array
    for (int i = 0; i < elem; ++i) {
        t->seating[i] = NULL;
    }

    // For demonstration only: Manually allocate two patrons
    t->seating[0] = malloc(sizeof(struct patron));
    t->seating[1] = malloc(sizeof(struct patron));

    // Check for successful allocation before using the structures
    if (t->seating[0] && t->seating[1]) {
        strcpy(t->seating[0]->first_name, "Alice");
        strcpy(t->seating[0]->last_name, "Smith");

        strcpy(t->seating[1]->first_name, "Bob");
        strcpy(t->seating[1]->last_name, "Johnson");
    } else {
        fprintf(stderr, "Memory allocation for patrons failed\n");
        free(t->seating[0]); // Ensure we don't leak memory
        free(t->seating[1]); // We free here just for defensive coding
        exit(1);
    }
}
