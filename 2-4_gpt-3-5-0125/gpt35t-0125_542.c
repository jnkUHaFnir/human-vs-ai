void init(int elem, struct theatre_seating *t) {
    t->seating = (struct patron **)malloc(elem * sizeof(struct patron *));
    
    for (int i = 0; i < elem; i++) {
        t->seating[i] = (struct patron *)malloc(sizeof(struct patron));
    }
}
t->seating[0]->first_name
void cleanup(struct theatre_seating *t, int elem) {
    for (int i = 0; i < elem; i++) {
        free(t->seating[i]);
    }
    free(t->seating);
}
