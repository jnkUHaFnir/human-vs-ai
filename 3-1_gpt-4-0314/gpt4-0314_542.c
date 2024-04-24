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
void cleanup(int elem, struct theatre_seating *t);

int main() {
    struct theatre_seating theatre_seating;
    int elem = 2;

    init(elem, &theatre_seating);

    // Access patron data like this:
    // strcpy(t->seating[0]->first_name, "John");
    // printf("First_name: %s\n", t->seating[0]->first_name);

    cleanup(elem, &theatre_seating);

    return 1;
}

void init(int elem, struct theatre_seating *t) {
    t->seating = (struct patron **) malloc(elem * sizeof(struct patron *));
    
    for (int i = 0; i < elem; ++i) {
        t->seating[i] = (struct patron *) malloc(sizeof(struct patron));
    }
}

void cleanup(int elem, struct theatre_seating *t) {
    for (int i = 0; i < elem; ++i) {
        free(t->seating[i]);
    }
    
    free(t->seating);
}
