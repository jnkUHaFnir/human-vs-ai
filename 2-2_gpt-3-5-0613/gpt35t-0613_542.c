void init(int elem, struct theatre_seating *t) {
    // Allocate memory for the seating array
    t->seating = malloc(sizeof(struct patron*) * elem);
    
    // Check if the memory allocation was successful
    if (t->seating == NULL) {
        printf("Memory allocation error");
        return;
    }
    
    // Allocate memory for each element in the seating array
    for (int i = 0; i < elem; i++) {
        t->seating[i] = malloc(sizeof(struct patron));
        
        // Check if the memory allocation was successful
        if (t->seating[i] == NULL) {
            printf("Memory allocation error");
            return;
        }
    }
}
