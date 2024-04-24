void init(int elem, struct theatre_seating *t) {
    // Allocate memory for the array of pointers to patrons
    t->seating = (struct patron **)malloc(elem * sizeof(struct patron *));

    // Check if memory allocation was successful
    if (t->seating == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    // Allocate memory for each individual patron struct
    for (int i = 0; i < elem; i++) {
        t->seating[i] = (struct patron *)malloc(sizeof(struct patron));

        // Check if memory allocation was successful
        if (t->seating[i] == NULL) {
            fprintf(stderr, "Failed to allocate memory\n");

            // Free previously allocated memory to avoid memory leaks
            for (int j = 0; j < i; j++) {
                free(t->seating[j]);
            }
            free(t->seating);
            exit(1);
        }
    }
}
