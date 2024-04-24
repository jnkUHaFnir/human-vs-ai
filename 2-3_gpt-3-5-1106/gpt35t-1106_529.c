struct symbol_table *symbol_table_create(void) {
  struct symbol_table *stt = malloc(sizeof(struct symbol_table));
  stt->count = 3;  // Assuming you want to have 3 elements in the array
  stt->arr = malloc(sizeof(struct str_id) * stt->count);

  // Allocate memory for each struct str_id element in the array
  for (int i = 0; i < stt->count; i++) {
    stt->arr[i].s = malloc(MAX_STRING_LENGTH * sizeof(char));  // Assuming MAX_STRING_LENGTH is the maximum length of your symbol strings
  }

  // Now you can initialize the elements of the array with your symbol strings and ids

  return stt;
}
