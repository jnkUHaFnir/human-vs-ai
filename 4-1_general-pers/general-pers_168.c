typedef struct myStruct {
    int size;
    char *name;
    myStruct *array[5]; // Array of 5 pointers to myStruct
} myStruct;
myStruct *a = malloc(sizeof(myStruct)); // Allocate memory for a single myStruct

// Now, allocate memory for the elements in the array
for (int i = 0; i < 5; i++) {
    a->array[i] = malloc(sizeof(myStruct)); // Allocate memory for each element in the array
}
// Free memory for each element in the array
for (int i = 0; i < 5; i++) {
    free(a->array[i]);
}

// Free memory for the main struct
free(a);
