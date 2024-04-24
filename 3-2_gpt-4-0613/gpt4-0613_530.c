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
  stt->count = 1;
  stt->arr =  malloc(sizeof(struct str_id*) * stt->count);
  
  // Allocate memory for each individual str_id structure that the arr pointers can point to
  for(int i = 0; i < stt->count; i++) {
    stt->arr[i] = malloc(sizeof(struct str_id));
  }

  return stt;
}
