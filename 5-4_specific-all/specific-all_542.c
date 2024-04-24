#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc

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

    // Example: Accessing patron data
    // Assuming elem > 0 for simplicity
    strcpy(theatre_seating.seating[0]->first_name, "Alice");
    strcpy(theatre_seating.seating[0]->last_name, "Smith");

    printf("First patron's first name: %s\n", theatre_seating.seating[0]->first_name);
    printf("First patron's last name: %s\n", theatre_seating.seating[0]->last_name);

    // Don't forget to free the allocated memory when done
    free(theatre_seating.seating[0]);
    free(theatre_seating.seating[1]);
    free(theatre_seating.seating);

    return 0;
}

void init(int elem, struct theatre_seating *t) {
    int i;
    t->seating = (struct patron **)malloc(elem * sizeof(struct patron *));

    for (i = 0; i < elem; i++) {
        t->seating[i] = (struct patron *)malloc(sizeof(struct patron));
    }
}
