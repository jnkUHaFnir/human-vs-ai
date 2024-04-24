void init(int elem, struct theatre_seating *t) {
    // Allocate memory for the seating array
    t->seating = malloc(elem * sizeof(struct patron*));

    // Check if memory allocation was successful
    if (t->seating == NULL) {
        printf("Error allocating memory for seating array\n");
        return;
    }

    // Allocate memory for each individual patron in the seating array
    for (int i = 0; i < elem; i++) {
        t->seating[i] = malloc(sizeof(struct patron));
    }

    // Now you can access the patron data like this:
    t->seating[0]->first_name = "John";
    t->seating[1]->first_name = "Jane";
}
