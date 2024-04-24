#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct str_id {
  char* s;
  int id;
};

struct symbol_table {
  int count;
  struct str_id* arr; // Change to struct str_id* instead of struct str_id**
};

struct symbol_table *symbol_table_create(void) {
  struct symbol_table *stt = malloc(sizeof(struct symbol_table)); // Check if malloc succeeded
  if (stt == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }

  stt->count = 0; // Initialize count to 0 initially
  stt->arr = NULL; // Initialize array to NULL initially

  return stt;
}

void symbol_table_insert(struct symbol_table *stt, const char *s, int id) {
  if (stt == NULL) {
    fprintf(stderr, "Symbol table is NULL\n");
    return;
  }

  stt->count++;
  stt->arr = realloc(stt->arr, sizeof(struct str_id) * stt->count); // Check if realloc succeeded
  if (stt->arr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return;
  }

  stt->arr[stt->count - 1].s = strdup(s); // Safely copy the input string
  stt->arr[stt->count - 1].id = id;
}

void symbol_table_destroy(struct symbol_table *stt) {
  if (stt == NULL) {
    return;
  }

  for (int i = 0; i < stt->count; i++) {
    free(stt->arr[i].s); // Free all dynamically allocated strings
  }
  free(stt->arr); // Free the array itself
  free(stt); // Free the symbol table struct
}

int main() {
  struct symbol_table *stt = symbol_table_create();

  symbol_table_insert(stt, "sym1", 1);
  symbol_table_insert(stt, "sym2", 2);
  symbol_table_insert(stt, "sym3", 3);

  symbol_table_destroy(stt);

  return 0;
}
