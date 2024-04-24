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

int main() {
    struct theatre_seating theatre_seating;

    int elem = 2;

    init(elem, &theatre_seating);

    // Access example: printf("%s\n", theatre_seating.seating[0]->first_name);

    // Don't forget to free the memory allocated for seating
    for (int i = 0; i < elem; i++) {
        free(theatre_seating.seating[i]);
    }
    free(theatre_seating.seating);

    return 0;
}

void init(int elem, struct theatre_seating *t) {
    t->seating = malloc(elem * sizeof(struct patron*));
    if (t->seating == NULL) {
        // Handle memory allocation failure
        exit(1);
    }

    for (int i = 0; i < elem; i++) {
        t->seating[i] = malloc(sizeof(struct patron));
        if (t->seating[i] == NULL) {
            // Handle memory allocation failure
            exit(1);
        }
    }
}
