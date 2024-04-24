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

    // Accessing patron data
    theatre_seating.seating[0]->first_name = "John";
    theatre_seating.seating[0]->last_name = "Doe";

    printf("First patron's first name: %s\n", theatre_seating.seating[0]->first_name);

    // Don't forget to free memory
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
}
