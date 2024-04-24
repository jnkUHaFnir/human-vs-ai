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
    struct theatre_seating theatre;
    int elem = 2;

    init(elem, &theatre);

    /* Accessing patron details using pointer to the allocated memory */
    sprintf(theatre.seating[0]->first_name, "First Name 1");
    sprintf(theatre.seating[0]->last_name, "Last Name 1");
    sprintf(theatre.seating[1]->first_name, "First Name 2");
    sprintf(theatre.seating[1]->last_name, "Last Name 2");

    /* Print the patrons */
    int i;
    for (i = 0; i < elem; ++i) {
        printf("Patron %d:\n", i);
        printf("First Name: %s\n", theatre.seating[i]->first_name);
        printf("Last Name: %s\n", theatre.seating[i]->last_name);
    }

    /* Don't forget to free the allocated memory */
    for (i = 0; i < elem; ++i) {
        free(theatre.seating[i]);
    }
    free(theatre.seating);

    return 1;
}

void init(int elem, struct theatre_seating *t) {
    /* Allocate memory for `elem` pointers to `struct patron` */
    t->seating = (struct patron **) malloc(elem * sizeof(struct patron *));
    /* Assume the malloc succeeded, and allocate memory for each `struct patron` */
    for (int i = 0; i < elem; ++i) {
        t->seating[i] = (struct patron *) malloc(sizeof(struct patron));
    }
}
