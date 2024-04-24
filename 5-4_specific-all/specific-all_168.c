typedef struct myStruct myStruct;
struct myStruct{
  int size;
  char *name;
  myStruct **array;
};
int array_size = 5;
myStruct *a = malloc(sizeof(myStruct));
a->array = malloc(array_size * sizeof(myStruct *));
for (int i = 0; i < array_size; i++) {
    a->array[i] = malloc(sizeof(myStruct));
}
// Free memory for each element in the array
for (int i = 0; i < array_size; i++) {
    free(a->array[i]);
}
// Free the array of pointers
free(a->array);
// Free the struct itself
free(a);
