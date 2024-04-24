void init(int elem, struct theatre_seating *t) {
    t->seating = malloc(elem * sizeof(struct patron *)); // Allocate memory for 'elem' number of pointers to struct patron

    for (int i = 0; i < elem; i++) {
        t->seating[i] = malloc(sizeof(struct patron)); // Allocate memory for each struct patron
    }

    // Example of accessing patron data
    strcpy(t->seating[0]->first_name, "John");
    strcpy(t->seating[0]->last_name, "Doe");
}
// Free allocated memory
for (int i = 0; i < elem; i++) {
    free(t->seating[i]);
}
free(t->seating);
