    #include <stdio.h>
    // First you need to include necessary header files,
    // to invoke memory allocation functions,
    // such as `malloc`, `calloc`, etc.
    #include <stdlib.h>
    struct patron {
        // Beware the following declaration leads to inefficient memory usage
        char last_name[30];
        char first_name[30];
    };
    struct theatre_seating {
        // Keeps a track of how long the following array is
        size_t len_seating;
        // Array pointer
        struct patron * seating;
    };
    int init(int elem, struct theatre_seating *t);
    int main() {
        // Usually people initialize a `struct` with `{ 0 }`
        // to make sure every member in it is empty,
        // and to prevent undefined behaviour
        struct theatre_seating theatre_seating = { 0 };
        int elem = 2;
        if (init(elem, &theatre_seating))
        {
            // TODO
        }
        // ALWAYS remember to destroy
        // dynamically allocated memory
        // at the end of the thread
        free(theatre_seating.seating);
        // Instead of (1), return (0) to indicate successful result.
        return 0;
    }
    // I don't know what argument `elem` stands for
    // but I assume that it stands for the number of seats
    // (aka. the length of `seating` array)
    //
    // @return: 1, upon successful memory allocation
    //          0, otherwise
    int init(int elem, struct theatre_seating *t) {
        t->len_seating = elem;
        t->seating = calloc(elem, sizeof(struct patron));
        // Remember to check if dynamic allocation is successful
        return t->seating;
    }