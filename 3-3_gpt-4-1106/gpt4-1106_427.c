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

    if (!*dummies) {  // (Notice the change here to check if *dummies is non-null)
        return 1; // allocation unsuccessful
    }

    // Iterate dummies and assign their values...
    for (int i = 0; i < *num_of_dummies; i++) {
        (*dummies + i)->dummy_number = i;
    }

    return 0;
}

int main() {  // (main should return int)
    Dummy* d;
    int num_of_dummies = 0;
    int *p_num_of_dummies = &num_of_dummies;
    int err;

    // Allocate a pointer for dummies
    Dummy** dummy_ptr = &d;  
    err = load_dummies(dummy_ptr, p_num_of_dummies);

    // You can now avoid an additional dereference and just use 'd'
    if (err) {
        exit(err);
    }

    for (int i = 0; i < num_of_dummies; i++) {
        printf("Dummy number: %d\n", d[i].dummy_number); // Accessing using the d pointer
    }

    free(d); // Do not forget to free the memory allocated with calloc

    return 0;
}
