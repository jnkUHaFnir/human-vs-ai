void main() {
    Dummy* dummies;  // Change to single pointer
    int num_of_dummies = 0;
    int *p_num_of_dummies = &num_of_dummies;
    int err;

    // Allocate memory for the double pointer
    dummies = (Dummy **)malloc(sizeof(Dummy*));

    err = load_dummies(&dummies, p_num_of_dummies);  // Pass the address of the single pointer

    d = dummies;  // No segmentation fault should occur now

    if (err) {
        exit(err);
    }

    for (int i = 0; i < num_of_dummies; i++) {
        printf("Dummy number: %d\n", (d + i)->dummy_number);  // Access the array using the single pointer
    }

    // Don't forget to free the allocated memory at the end
    free(dummies);
}
