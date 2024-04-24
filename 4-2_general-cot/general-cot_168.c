typedef struct myStruct myStruct;
struct myStruct {
    int size;
    char *name;
    myStruct **array; // Changed to double pointer
};
myStruct *a = malloc(sizeof(myStruct));
a->array = malloc(5 * sizeof(myStruct *)); // Allocating space for 5 myStruct pointers

// Allocate memory for each myStruct element in the array
for (int i = 0; i < 5; i++) {
    a->array[i] = malloc(sizeof(myStruct));
}
// Free memory for each element in the array
for (int i = 0; i < 5; i++) {
    free(a->array[i]);
}

// Free the array of pointers and then the main struct
free(a->array);
free(a);
