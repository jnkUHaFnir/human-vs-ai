Dummy** dummies;
Dummy* d;
err = load_dummies(dummies, p_num_of_dummies);
void main() { // It's better to use int main() than void main()
    Dummy* d;
    int num_of_dummies = 0;

    // Initialize dummies to point to NULL
    Dummy** dummies = NULL;

    // Dynamically allocate space for dummies to ensure it has a valid address
    dummies = malloc(sizeof(*dummies));
    if (!dummies) {
        exit(1); // Memory allocation failure
    }

    int err = load_dummies(dummies, &num_of_dummies);

    if (err) {
        exit(err);
    }

    d = *dummies; // This should now work as expected

    for (int i = 0; i < num_of_dummies; i++) {
        printf("Dummy number: %d\n", d[i].dummy_number);
    }

    // Remember to free the allocated memory to avoid memory leaks
    free(*dummies);
    free(dummies);

    // Returning from main() is a good practice
    return 0;
}
