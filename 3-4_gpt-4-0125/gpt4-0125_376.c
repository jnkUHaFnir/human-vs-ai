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

    if (!*dummies) {   // Corrected check for NULL after allocation
        return 1; // allocation unsuccessful
    }

    for (int i = 0; i < *num_of_dummies; i++) {
        (*dummies)[i].dummy_number = i;  // Cleaner way to access array elements
    }

    return 0;
}

int main() {  // `int main()` is the standard signature for the main function
    Dummy* dummies = NULL; // Changed to a single pointer
    int num_of_dummies = 0;
    int err;

    // Using the address of 'dummies', which is of type `Dummy**`
    err = load_dummies(&dummies, &num_of_dummies);

    // Now that dummies has been properly assigned in load_dummies, this is safe
    if (err) {
        exit(err);
    }

    for (int i = 0; i < num_of_dummies; i++) {
        printf("Dummy number: %d\n", dummies[i].dummy_number);  // Adjusted access to dummy_number
    }

    free(dummies); // Don't forget to free the allocated memory!

    return 0;  // Return 0 to indicate success
}
