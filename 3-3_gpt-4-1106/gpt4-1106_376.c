int main() { // `void main` is not standard; use `int main` instead
    Dummy* dummies; // This should be a single-level pointer.
    Dummy* d;
    int num_of_dummies = 0;
    int *p_num_of_dummies = &num_of_dummies;
    int err;

    // Pass the address of `dummies` so it points to the allocated array after calling `load_dummies`
    err = load_dummies(&dummies, p_num_of_dummies);

    if (err) {
        exit(err);
    }

    // Now you can assign `d` directly
    d = dummies;

    // Use the `d` pointer to access the `Dummy` array
    for (int i = 0; i < num_of_dummies; i++) {
        printf("Dummy number: %d\n", (d + i)->dummy_number);
    }
    
    // Free the allocated memory at the end
    free(dummies);

    return 0; // Return zero to indicate successful execution
}
if (!(*dummies)) {
    return 1; // allocation unsuccessful
}
