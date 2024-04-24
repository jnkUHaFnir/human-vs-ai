void main() {
    Dummy* d;
    int num_of_dummies = 0;
    int *p_num_of_dummies = &num_of_dummies;
    int err;

    // Allocate memory for dummies pointer
    Dummy** dummies = (Dummy**)malloc(sizeof(Dummy*));

    // Call load_dummies with the address of dummies pointer
    err = load_dummies(dummies, p_num_of_dummies);

    // Check if allocation was successful
    if (err) {
        exit(err);
    }

    // Dereference dummies pointer to get the address of the dynamically allocated array
    d = *dummies;

    for (int i = 0; i < num_of_dummies; i++) {
        printf("Dummy number: %d\n", d[i].dummy_number);
    }

    // Free the dynamically allocated memory
    free(d);
    free(dummies);
}
