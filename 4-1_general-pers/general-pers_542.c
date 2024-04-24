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

    // Accessing patron's first name from first seating position
    printf("%s\n", theatre_seating.seating[0]->first_name);

    // Free allocated memory
    for (int i = 0; i < elem; i++) {
        free(theatre_seating.seating[i]);
    }
    free(theatre_seating.seating);

    return 1;
}

void init(int elem, struct theatre_seating *t) {
    t->seating = (struct patron **)malloc(elem * sizeof(struct patron *));
    if (t->seating == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Initializing each patron within the seating array
    for (int i = 0; i < elem; i++) {
        t->seating[i] = (struct patron *)malloc(sizeof(struct patron));
        if (t->seating[i] == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
    }

    // Example: Setting the first patron's first name
    snprintf(t->seating[0]->first_name, sizeof(t->seating[0]->first_name), "John");
}
