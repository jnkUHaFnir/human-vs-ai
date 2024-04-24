#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patron {
   char last_name[30];
   char first_name[30];
};

struct theatre_seating {
    struct patron *seating; // it can be a single pointer because you are creating an array of struct
};

void init(int elem, struct theatre_seating *t);

int main() {
    struct theatre_seating theatre_seating;
    int elem = 2;

    init(elem, &theatre_seating);

    // Access attribute
    strcpy(theatre_seating.seating[0].first_name, "John");
    strcpy(theatre_seating.seating[0].last_name, "Doe");

    printf("First patron: %s %s\n", theatre_seating.seating[0].first_name, theatre_seating.seating[0].last_name);

    // Remember to free allocated memory 
    free(theatre_seating.seating);

    return 0;
}

void init(int elem, struct theatre_seating *t) {
    
    // Here you allocate memory for 'elem' number of struct patron
    // The sizeof operator is used to get the number of bytes needed to store an element of such struct
    t->seating = (struct patron*) malloc(elem * sizeof(struct patron));
    
    // Always remember to check whether the memory was successfully obtained
    if (t->seating == NULL) {
        printf("Unable to allocate memory.\n");
        exit(0); // or return an error code
    }
}
