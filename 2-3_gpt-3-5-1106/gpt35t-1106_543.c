void init(int elem, struct theatre_seating *t) {
    t->seating = (struct patron**)malloc(elem * sizeof(struct patron*)); // Allocate memory for array of pointers

    // Loop through the array and allocate memory for each patron struct
    for (int i = 0; i < elem; i++) {
        t->seating[i] = (struct patron*)malloc(sizeof(struct patron));
    }
}
// Free memory for each patron struct
for (int i = 0; i < elem; i++) {
    free(t->seating[i]);
}

// Free memory for the array of pointers
free(t->seating);
