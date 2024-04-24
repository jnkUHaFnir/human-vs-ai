#include <stdio.h>
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
  if (stt == NULL) {
    // Handle memory allocation failure
    return NULL;
  }

  stt->count = 1;
  stt->arr = malloc(sizeof(struct str_id*) * stt->count);
  if (stt->arr == NULL) {
    free(stt);
    // Handle memory allocation failure
    return NULL;
  }

  stt->arr[0] = malloc(sizeof(struct str_id)); // Allocating memory for the first str_id
  if (stt->arr[0] == NULL) {
    free(stt->arr);
    free(stt);
    // Handle memory allocation failure
    return NULL;
  }

  stt->arr[0]->s = strdup("sym1"); // You can use strdup to allocate and copy the string
  stt->arr[0]->id = 1;

  return stt;
}

int main() {
  struct symbol_table *st = symbol_table_create();
  if (st != NULL) {
    printf("%s %d\n", st->arr[0]->s, st->arr[0]->id);
  }

  return 0;
}
