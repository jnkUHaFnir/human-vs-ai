#include <stdio.h>
#include <stdlib.h> // For malloc, free

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
    theatre_seating.seating[0]->first_name[0] = 'J';
    theatre_seating.seating[0]->first_name[1] = 'o';
    theatre_seating.seating[0]->first_name[2] = 'h';
    theatre_seating.seating[0]->first_name[3] = 'n';
    theatre_seating.seating[0]->first_name[4] = '\0';

    printf("First name of first patron: %s\n", theatre_seating.seating[0]->first_name);

    // Don't forget to free memory

    return 0;
}

void init(int elem, struct theatre_seating *t) {
    t->seating = malloc(elem * sizeof(struct patron *));

    for (int i = 0; i < elem; i++) {
        t->seating[i] = malloc(sizeof(struct patron));
    }
}

