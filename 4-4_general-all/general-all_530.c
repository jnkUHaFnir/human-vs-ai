#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct str_id {
  char *s;
  int id;
};

struct symbol_table {
  int count;
  struct str_id *arr;
};

struct symbol_table *symbol_table_create(void) {
  struct symbol_table *stt = malloc(sizeof(struct symbol_table));
  if (stt == NULL) {
    // Handle memory allocation failure
    return NULL;
  }

  stt->count = 3; // Setting initial count to 3 as in your example
  stt->arr = malloc(sizeof(struct str_id) * stt->count);
  if (stt->arr == NULL) {
    free(stt); // Release the previously allocated memory
    // Handle memory allocation failure
    return NULL;
  }

  stt->arr[0].s = strdup("sym1");
  stt->arr[0].id = 1;
  stt->arr[1].s = strdup("sym2");
  stt->arr[1].id = 2;
  stt->arr[2].s = strdup("sym3");
  stt->arr[2].id = 3;

  return stt;
}

int main() {
  struct symbol_table *st = symbol_table_create();
  if (st == NULL) {
    // Handle creation failure
    return 1;
  }

  // Access and print the symbol table
  for (int i = 0; i < st->count; i++) {
    printf("{ \"%s\", %d } ", st->arr[i].s, st->arr[i].id);
  }

  // Free memory
  for (int i = 0; i < st->count; i++) {
    free(st->arr[i].s);
  }
  free(st->arr);
  free(st);

  return 0;
}
