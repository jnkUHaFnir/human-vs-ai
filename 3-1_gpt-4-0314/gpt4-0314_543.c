#include <stdio.h>
#include <stdlib.h> // for malloc

struct patron {
   char last_name[30];
   char first_name[30];
};

struct theatre_seating {
    struct patron *seating; // change this to a single pointer
};

void init(int elem, struct theatre_seating *t);


int main() {
    struct theatre_seating theatre_seating;

    int elem = 2;

    init(elem, &theatre_seating);

    // Accessing patron data
    printf("First Name: %s\n", theatre_seating.seating[0].first_name);

    // Free memory
    free(theatre_seating.seating);

    return 1;
}

void init(int elem, struct theatre_seating *t) {
    t->seating = (struct patron *)malloc(elem * sizeof(struct patron));

    // Initialize two patrons
    strcpy(t->seating[0].first_name, "John");
    strcpy(t->seating[0].last_name, "Doe");
    strcpy(t->seating[1].first_name, "Jane");
    strcpy(t->seating[1].last_name, "Doe");
}
