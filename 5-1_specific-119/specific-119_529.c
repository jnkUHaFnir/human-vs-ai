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
  if (stt == NULL) {
    printf("Memory allocation failed. Exiting.");
    exit(EXIT_FAILURE);
  }

  stt->count = 3; // Set initial count to 3 as per your example
  stt->arr = malloc(sizeof(struct str_id) * stt->count);
  if (stt->arr == NULL) {
    printf("Memory allocation failed. Exiting.");
    free(stt);
    exit(EXIT_FAILURE);
  }

  // Initialize the array with sample data
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

  // Access and print the data for demonstration
  for (int i = 0; i < st->count; i++) {
    printf("Symbol: %s, ID: %d\n", st->arr[i].s, st->arr[i].id);
    free(st->arr[i].s); // Free the memory allocated by strdup
  }

  free(st->arr); // Free the memory allocated for the array
  free(st);      // Free the memory allocated for the symbol table

  return 0;
}
