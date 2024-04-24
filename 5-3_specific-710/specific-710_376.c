#include <stdlib.h>
#include <stdio.h>

typedef struct s_dummy {
    char dummy_number;  
} Dummy;

int mock_read_from_external_source() {
    return 4;
}

int load_dummies(Dummy** dummies, int* num_of_dummies) {
    *num_of_dummies = mock_read_from_external_source();
    *dummies = (Dummy*) calloc(*num_of_dummies, sizeof(Dummy));

    if (!(*dummies)) {
        return 1; // allocation unsuccessful
    }

    // Iterate dummies and assign their values...
    for (int i = 0; i < *num_of_dummies; i++) {
        (*dummies + i)->dummy_number = i;
    }

    return 0;
}

void main() {
    Dummy** dummies = NULL; // Initialize the pointer
    Dummy* d;
    int num_of_dummies = 0;
    int* p_num_of_dummies = &num_of_dummies;
    int err;

    err = load_dummies(&dummies, p_num_of_dummies); // Pass the address of the pointer

    if (err) {
        exit(err);
    }

    d = *dummies; // Now it is safe to dereference

    for (int i = 0; i < num_of_dummies; i++) {
        printf("Dummy number: %d\n", d[i].dummy_number);
    }

    free(*dummies); // Don't forget to free the allocated memory
}
