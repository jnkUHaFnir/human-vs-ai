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

    if (!*dummies) { // Change this line: check *dummies instead of dummies, you're checking the allocated memory
        return 1; // allocation unsuccessful
    }

    for (int i = 0; i < *num_of_dummies; i++) {
        (*dummies + i)->dummy_number = i;
    }

    return 0;
}

int main() { // Change return type to int
    Dummy* dummy_array; // We only need a single pointer as the array will be a contiguous block of memory
    int num_of_dummies = 0;
    int err;

    err = load_dummies(&dummy_array, &num_of_dummies);

    if (err) {
        exit(err);
    }

    for (int i = 0; i < num_of_dummies; i++) {
        printf("Dummy number: %d\n", (dummy_array + i)->dummy_number);
    }

    free(dummy_array); // Do not forget to free the calloc'ed memory

    return 0;
}
