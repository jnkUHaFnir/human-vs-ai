#include <stdio.h>
#include <stdlib.h> // Included for malloc and free

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

    // Accessing patron data
    strcpy(theatre_seating.seating[0]->first_name, "John");
    strcpy(theatre_seating.seating[0]->last_name, "Doe");
    strcpy(theatre_seating.seating[1]->first_name, "Jane");
    strcpy(theatre_seating.seating[1]->last_name, "Smith");

    // Example print
    printf("First patron's name: %s %s\n", theatre_seating.seating[0]->first_name, theatre_seating.seating[0]->last_name);
    printf("Second patron's name: %s %s\n", theatre_seating.seating[1]->first_name, theatre_seating.seating[1]->last_name);

    // Don't forget to free memory after use to prevent memory leaks
    free(theatre_seating.seating[0]);
    free(theatre_seating.seating[1]);
    free(theatre_seating.seating);
    
    return 1;
}

void init(int elem, struct theatre_seating *t) {
    t->seating = (struct patron **)malloc(elem * sizeof(struct patron *)); // Allocate memory for seating array
    
    for (int i = 0; i < elem; i++) {
        t->seating[i] = (struct patron *)malloc(sizeof(struct patron)); // Allocate memory for each patron
    }
}
