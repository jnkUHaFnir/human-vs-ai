#include <stdio.h>
#include <stdlib.h>

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

    // Access sample patron data
    theatre_seating.seating[0]->first_name = "Alice";
    theatre_seating.seating[0]->last_name = "Smith";
    theatre_seating.seating[1]->first_name = "Bob";
    theatre_seating.seating[1]->last_name = "Johnson";

    // Output sample data
    for (int i = 0; i < elem; i++) {
        printf("Patron %d: %s %s\n", i + 1, theatre_seating.seating[i]->first_name, theatre_seating.seating[i]->last_name);
    }

    // Free allocated memory
    for (int i = 0; i < elem; i++) {
        free(theatre_seating.seating[i]);
    }
    free(theatre_seating.seating);

    return 1;
}

void init(int elem, struct theatre_seating *t) {
    t->seating = (struct patron **)malloc(elem * sizeof(struct patron *));
    for (int i = 0; i < elem; i++) {
        t->seating[i] = (struct patron *)malloc(sizeof(struct patron));
    }
}
