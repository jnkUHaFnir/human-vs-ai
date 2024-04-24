#include <stdio.h>
#include <stdlib.h> // For malloc

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

    // Accessing the first patron's first name
    printf("First name of the first patron: %s\n", theatre_seating.seating[0]->first_name);

    return 1;
}

void init(int elem, struct theatre_seating *t) {
    // Allocate memory for the seating array
    t->seating = (struct patron **)malloc(elem * sizeof(struct patron *));
    
    // Check if memory allocation was successful
    if (t->seating == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // Exit with failure
    }
    
    // Initialize each patron within the seating array
    for (int i = 0; i < elem; i++) {
        t->seating[i] = (struct patron *)malloc(sizeof(struct patron));
        
        // Check if memory allocation was successful
        if (t->seating[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1); // Exit with failure
        }
        
        // Initialize the first name and last name of each patron
        // For example, setting some sample values
        sprintf(t->seating[i]->first_name, "First%d", i+1);
        sprintf(t->seating[i]->last_name, "Last%d", i+1);
    }
}
