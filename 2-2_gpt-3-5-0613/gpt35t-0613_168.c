typedef struct myStruct myStruct;
struct myStruct{
  int size;
  char *name;
  myStruct *array[5]; // Replace 5 with the desired size
};
myStruct *a = malloc(sizeof(myStruct));
a->size = 5;
a->name = "example";

for (int i = 0; i < a->size; i++) {
  a->array[i] = malloc(sizeof(myStruct));
  // additional initialization if needed
}
for (int i = 0; i < a->size; i++) {
  free(a->array[i]);
}
free(a);
