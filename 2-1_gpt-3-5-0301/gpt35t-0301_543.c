void init(int elem, struct theatre_seating *t) {
    // Allocate memory for an array of struct patron pointers
    t->seating = malloc(elem * sizeof(struct patron *));

    // Initialize each element in the array with a new struct patron
    for (int i = 0; i < elem; i++) {
        t->seating[i] = malloc(sizeof(struct patron));
    }

    // Set the first patron's first and last name
    strcpy(t->seating[0]->first_name, "John");
    strcpy(t->seating[0]->last_name, "Doe");

    // Set the second patron's first and last name
    strcpy(t->seating[1]->first_name, "Jane");
    strcpy(t->seating[1]->last_name, "Doe");
}
t->seating[0]->first_name // "John"
t->seating[0]->last_name // "Doe"
t->seating[1]->first_name // "Jane"
t->seating[1]->last_name // "Doe"
