void init(int elem, struct theatre_seating *t) {
    t->seating = malloc(elem * sizeof(struct patron*)); // allocate memory for the array of pointers to patrons

    for (int i = 0; i < elem; i++) {
        t->seating[i] = malloc(sizeof(struct patron)); // allocate memory for each individual patron
    }
}
