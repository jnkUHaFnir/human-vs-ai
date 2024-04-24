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

int main() {
    Dummy** dummies = NULL;
    Dummy* d;
    int num_of_dummies = 0;
    int *p_num_of_dummies = &num_of_dummies;
    int err;

    dummies = (Dummy**)malloc(sizeof(Dummy*)); // Allocate memory for the pointer

    err = load_dummies(dummies, p_num_of_dummies);

    // Check for error during loading
    if (err) {
        free(*dummies); // Free memory if allocation was not successful
        free(dummies); // Free memory for the pointer
        exit(err);
    }

    d = *dummies;

    for (int i = 0; i < num_of_dummies; i++) {
        printf("Dummy number: %d\n", (*d + i)->dummy_number);
    }

    free(*dummies); // Free memory allocated for the Dummy objects
    free(dummies); // Free memory allocated for the pointer
    return 0;
}
