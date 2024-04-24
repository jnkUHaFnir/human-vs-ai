struct str_id {
  char* s;
  int id;
};

struct symbol_table {
  int count;
  struct str_id* arr;
};

struct symbol_table *symbol_table_create(int count) {
  struct symbol_table *stt = malloc(sizeof(struct symbol_table));
  stt->count = count;
  stt->arr = malloc(sizeof(struct str_id) * count);
  return stt;
}

void symbol_table_destroy(struct symbol_table *stt) {
  free(stt->arr);
  free(stt);
}

// example usage
int main() {
  struct symbol_table *stt = symbol_table_create(3);
  stt->arr[0] = (struct str_id){"sym1", 1};
  stt->arr[1] = (struct str_id){"sym2", 2};
  stt->arr[2] = (struct str_id){"sym3", 3};

  // use the symbol table...

  symbol_table_destroy(stt);
  return 0;
} 