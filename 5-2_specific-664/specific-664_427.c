int main() {
    Dummy** dummies = malloc(sizeof(Dummy*)); // Allocate memory for Dummy* pointer
    Dummy* d;
    int num_of_dummies = 0;
    int* p_num_of_dummies = &num_of_dummies;
    int err;

    if (!dummies) {
        return 1; // malloc failed
    }

    err = load_dummies(dummies, p_num_of_dummies);

    d = *dummies;

    if (err) {
        free(*dummies); // Free the allocated memory before exit
        free(dummies);
        exit(err);
    }

    for (int i = 0; i < num_of_dummies; i++) {
        printf("Dummy number: %d\n", (*dummies + i)->dummy_number);
    }

    free(*dummies); // Free the allocated memory
    free(dummies);

    return 0;
}
