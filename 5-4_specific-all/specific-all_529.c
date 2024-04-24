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
    // Handle allocation failure
    fprintf(stderr, "Memory allocation failed for symbol_table\n");
    exit(1);
  }
  
  stt->count = 3; // Initialize count to the total number of symbols
  stt->arr = malloc(sizeof(struct str_id*) * stt->count);
  if (stt->arr == NULL) {
    // Handle allocation failure
    fprintf(stderr, "Memory allocation failed for symbol_table array\n");
    free(stt);
    exit(1);
  }

  // Initialize each struct in the array
  for (int i = 0; i < stt->count; i++) {
    stt->arr[i] = malloc(sizeof(struct str_id));
    if (stt->arr[i] == NULL) {
      // Handle allocation failure
      fprintf(stderr, "Memory allocation failed for symbol_table entry\n");
      for (int j = 0; j < i; j++) {
        free(stt->arr[j]);
      }
      free(stt->arr);
      free(stt);
      exit(1);
    }
  }

  // Assign values to the symbols
  stt->arr[0]->s = strdup("sym1");
  stt->arr[0]->id = 1;
  
  stt->arr[1]->s = strdup("sym2");
  stt->arr[1]->id = 2;

  stt->arr[2]->s = strdup("sym3");
  stt->arr[2]->id = 3;

  return stt;
}

int main() {
  struct symbol_table *stt = symbol_table_create();
  
  // Access the created symbol table
  for (int i = 0; i < stt->count; i++) {
    printf("Symbol: %s, ID: %d\n", stt->arr[i]->s, stt->arr[i]->id);
    free(stt->arr[i]->s);
    free(stt->arr[i]);
  }
  free(stt->arr);
  free(stt);

  return 0;
}
