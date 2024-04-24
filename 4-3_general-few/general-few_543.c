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

    // Access patron data
    theatre_seating.seating[0]->first_name = "John";
    theatre_seating.seating[0]->last_name = "Doe";

    // Don't forget to free memory later

    return 0;
}

void init(int elem, struct theatre_seating *t) {
    t->seating = (struct patron **)malloc(elem * sizeof(struct patron *));

    for (int i = 0; i < elem; i++) {
        t->seating[i] = (struct patron *)malloc(sizeof(struct patron));
    }
}
