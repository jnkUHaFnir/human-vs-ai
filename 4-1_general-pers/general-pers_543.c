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
    printf("%s\n", theatre_seating.seating[0]->first_name);

    // Don't forget to free the allocated memory
    for (int i = 0; i < elem; i++) {
        free(theatre_seating.seating[i]);
    }
    free(theatre_seating.seating);

    return 0;
}

void init(int elem, struct theatre_seating *t) {
    // Allocate memory for the array of seating
    t->seating = (struct patron **)malloc(elem * sizeof(struct patron *));
    if (t->seating == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Allocate memory for each individual patron
    for (int i = 0; i < elem; i++) {
        t->seating[i] = (struct patron *)malloc(sizeof(struct patron));
        if (t->seating[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }
}
