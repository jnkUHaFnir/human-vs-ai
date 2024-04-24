typedef struct myStruct myStruct;
struct myStruct {
    int size;
    char *name;
    myStruct *(*array)[];
};
// Correctly allocating memory for myStruct and its flexible array
myStruct *a = malloc(sizeof(myStruct) + sizeof(myStruct*) * 5);
for (int i = 0; i < 5; ++i) {
    a->array[i] = malloc(sizeof(myStruct)); // Allocate each struct separately
}
a->array = malloc(sizeof(myStruct*) * 5); // Allocate space for 5 pointers to myStruct
for (int i = 0; i < 5; ++i) {
    a->array[i] = malloc(sizeof(myStruct)); // Allocate each struct separately
}
typedef struct myStruct {
    int size;
    char *name;
    myStruct **array; // Change to a double pointer to myStruct
} myStruct;
// Allocate memory for the top-level struct
myStruct *a = malloc(sizeof(myStruct));

// Allocate memory for the array of pointers within the struct
a->array = malloc(sizeof(myStruct*) * 5);

// Allocate memory for each individual myStruct pointed to by the pointers in the array
for (int i = 0; i < 5; ++i) {
    a->array[i] = malloc(sizeof(myStruct));
    // Initialize `size`, `name`, or any other members of `a->array[i]` as necessary
}
