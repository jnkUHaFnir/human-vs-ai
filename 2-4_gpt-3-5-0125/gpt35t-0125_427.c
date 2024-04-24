void main() {
    Dummy* dummies;
    Dummy* d;
    int num_of_dummies = 0;
    int* p_num_of_dummies = &num_of_dummies;
    int err;

    err = load_dummies(&dummies, p_num_of_dummies);

    d = dummies;

    if (err) {
        exit(err);
    }

    for (int i = 0; i < num_of_dummies; i++) {
        printf("Dummy number: %d\n", (d + i)->dummy_number);
    }
}
