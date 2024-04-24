struct str_id {
  char* s;
  int id;
};

struct symbol_table {
  int count;
  struct str_id** arr;
};
struct symbol_table {
  int count;
  struct str_id* arr; // Pointer to the first element of an array of str_id
};
struct symbol_table *symbol_table_create(void) {
  struct symbol_table *stt = malloc(sizeof(struct symbol_table));
  if (!stt) { // Check if malloc failed
    return NULL;
  }
  stt->count = 3;
  stt->arr = malloc(sizeof(struct str_id) * stt->count);
  if (!stt->arr) { // Check if malloc failed
    free(stt); // Free the previously allocated memory
    return NULL;
  }
  // Initialize the array with your desired values
  stt->arr[0] = (struct str_id){"sym1", 1};
  stt->arr[1] = (struct str_id){"sym2", 2};
  stt->arr[2] = (struct str_id){"sym3", 3};
  return stt;
}
