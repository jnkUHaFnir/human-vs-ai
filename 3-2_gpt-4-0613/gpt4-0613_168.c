typedef struct myStruct{
  int size;
  char *name;
  struct myStruct *array[5]; // array of 5 struct pointers
} myStruct;
myStruct *a = malloc(sizeof(myStruct));

// allocate each struct pointer inside array
for(int i=0; i<5; i++){
  (a->array[i]) = malloc(sizeof(myStruct));
}
typedef struct myStruct{
      int size;
      char *name;
      struct myStruct **array;
} myStruct;

myStruct *a = malloc(sizeof(myStruct));
a->size = 5; // allocate size dynamic memory for array

// allocating memory for array
a->array = (myStruct**)malloc(sizeof(myStruct*) * a->size);
for(int i=0; i < a->size; i++)
    a->array[i] = (myStruct*) malloc(sizeof(myStruct));
