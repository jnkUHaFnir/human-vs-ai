#include <stdio.h>
#include <stdlib.h> // Required for malloc

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

    // Access the first patron's first name
    printf("First name of the first patron: %s\n", theatre_seating.seating[0]->first_name);

    // Don't forget to free memory afterwards
    free(theatre_seating.seating[0]);
    free(theatre_seating.seating[1]);
    free(theatre_seating.seating);
    
    return 0;
}

void init(int elem, struct theatre_seating *t) {
    t->seating = (struct patron **)malloc(elem * sizeof(struct patron *));
    for (int i = 0; i < elem; i++) {
        t->seating[i] = (struct patron *)malloc(sizeof(struct patron));
    }

    // Initialize the first patron
    snprintf(t->seating[0]->first_name, sizeof(t->seating[0]->first_name), "Alice");
    snprintf(t->seating[0]->last_name, sizeof(t->seating[0]->last_name), "Smith");

    // Initialize the second patron
    snprintf(t->seating[1]->first_name, sizeof(t->seating[1]->first_name), "Bob");
    snprintf(t->seating[1]->last_name, sizeof(t->seating[1]->last_name), "Johnson");
}
