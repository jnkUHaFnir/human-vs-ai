#include <stdio.h>
#include <stdlib.h> // for malloc and free

struct patron {
    char last_name[30];
    char first_name[30];
};

struct theatre_seating {
    struct patron **seating; // Pointer to a pointer for dynamic allocation
};

void init(int elem, struct theatre_seating *t);

int main() {
    struct theatre_seating theatre_seating;
    int elem = 2;

    init(elem, &theatre_seating);

    // Access the first element of seating array and set values
    strcpy(theatre_seating.seating[0]->first_name, "Alice");
    strcpy(theatre_seating.seating[0]->last_name, "Smith");

    // Access the second element of seating array and set values
    strcpy(theatre_seating.seating[1]->first_name, "Bob");
    strcpy(theatre_seating.seating[1]->last_name, "Johnson");

    // Example: printing the first patron's first name
    printf("First patron's first name: %s\n", theatre_seating.seating[0]->first_name);

    // Don't forget to free memory after use
    for (int i = 0; i < elem; i++) {
        free(theatre_seating.seating[i]);
    }
    free(theatre_seating.seating);

    return 0;
}

void init(int elem, struct theatre_seating *t) {
    t->seating = malloc(elem * sizeof(struct patron*); // Allocate memory for array of pointers

    for (int i = 0; i < elem; i++) {
        t->seating[i] = malloc(sizeof(struct patron)); // Allocate memory for each patron struct
    }
}
