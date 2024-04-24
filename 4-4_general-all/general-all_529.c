#include <stdlib.h>
#include <string.h>

struct str_id {
  char* s;
  int id;
};

struct symbol_table {
  int count;
  struct str_id** arr;
};

struct symbol_table *symbol_table_create(void) {
  struct symbol_table *stt = malloc(sizeof(struct symbol_table));
  stt->count = 0; // Initialize the count to 0
  stt->arr = malloc(sizeof(struct str_id*) * stt->count);
  return stt;
}

void symbol_table_add(struct symbol_table *stt, const char* s, int id) {
  stt->count++;
  stt->arr = realloc(stt->arr, sizeof(struct str_id*) * stt->count);
  
  // Allocate memory for the new str_id struct
  stt->arr[stt->count - 1] = malloc(sizeof(struct str_id));
  
  // Allocate memory for the string and copy it
  stt->arr[stt->count - 1]->s = malloc(strlen(s) + 1);
  strcpy(stt->arr[stt->count - 1]->s, s);
  
  // Assign the ID
  stt->arr[stt->count - 1]->id = id;
}

void symbol_table_destroy(struct symbol_table *stt) {
  for (int i = 0; i < stt->count; i++) {
    free(stt->arr[i]->s);
    free(stt->arr[i]);
  }
  
  free(stt->arr);
  free(stt);
}

int main() {
  struct symbol_table *stt = symbol_table_create();
  
  symbol_table_add(stt, "sym1", 1);
  symbol_table_add(stt, "sym2", 2);
  symbol_table_add(stt, "sym3", 3);

  symbol_table_destroy(stt);
  
  return 0;
}
