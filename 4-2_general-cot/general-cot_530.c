#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct str_id {
  char* s;
  int id;
};

struct symbol_table {
  int count;
  struct str_id* arr;
};

struct symbol_table *symbol_table_create(void) {
  struct symbol_table *stt = malloc(sizeof(struct symbol_table));
  stt->count = 3; // Initialize count to the number of elements in the symbol table
  stt->arr = malloc(sizeof(struct str_id) * stt->count);
  
  // Initialize the individual elements
  stt->arr[0].s = strdup("sym1");
  stt->arr[0].id = 1;
  
  stt->arr[1].s = strdup("sym2");
  stt->arr[1].id = 2;

  stt->arr[2].s = strdup("sym3");
  stt->arr[2].id = 3;

  return stt;
}

void symbol_table_destroy(struct symbol_table *stt) {
  for (int i = 0; i < stt->count; i++) {
    free(stt->arr[i].s);
  }
  free(stt->arr);
  free(stt);
}

int main(void) {
  struct symbol_table *stt = symbol_table_create();
  
  // Access elements in the symbol table
  for (int i = 0; i < stt->count; i++) {
    printf("Symbol: %s, ID: %d\n", stt->arr[i].s, stt->arr[i].id);
  }
  
  symbol_table_destroy(stt);
  
  return 0;
}
