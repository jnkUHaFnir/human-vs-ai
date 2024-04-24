typedef struct myStruct myStruct;
struct myStruct {
    int size;
    char *name;
    myStruct **array;
};
myStruct *a = malloc(sizeof(myStruct));
a->size = 5; 
a->name = "example";

// Allocate memory for the array of pointers
a->array = malloc(sizeof(myStruct*) * a->size);

// Allocate memory for each element in the array
for (int i = 0; i < a->size; i++) {
    a->array[i] = malloc(sizeof(myStruct));
    // Initialize each element of the array as needed
}

// Don't forget to free memory when you are done using it
for (int i = 0; i < a->size; i++) {
    free(a->array[i]);
}
free(a->array);
free(a);
