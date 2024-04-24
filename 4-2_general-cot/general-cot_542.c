#include <stdio.h>
#include <stdlib.h> // Need to include this for malloc

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

    // Access the seating array and patron data
    for (int i = 0; i < elem; i++) {
        printf("First Name of patron %d: %s\n", i+1, theatre_seating.seating[i]->first_name);
    }

    return 0;
}

void init(int elem, struct theatre_seating *t) {
    t->seating = (struct patron **)malloc(elem * sizeof(struct patron *)); // Allocate memory for array of 'elem' pointers to patrons

    for (int i = 0; i < elem; i++) {
        t->seating[i] = (struct patron *)malloc(sizeof(struct patron)); // Allocate memory for each individual patron
    }

    // Initialize patron data
    // For example, initializing the first patron's data
    snprintf(t->seating[0]->first_name, sizeof(t->seating[0]->first_name), "Alice");
    snprintf(t->seating[0]->last_name, sizeof(t->seating[0]->last_name), "Smith");

    // Initialize the second patron's data
    snprintf(t->seating[1]->first_name, sizeof(t->seating[1]->first_name), "Bob");
    snprintf(t->seating[1]->last_name, sizeof(t->seating[1]->last_name), "Johnson");
}
