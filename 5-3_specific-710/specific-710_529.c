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
    return NULL;
  }
  
  stt->count = 0; // Initialize count to 0
  stt->arr = NULL; // Initialize arr to NULL
  
  return stt;
}

void symbol_table_add(struct symbol_table *stt, const char* s, int id) {
  if (stt == NULL) {
    // Handle NULL pointer error
    return;
  }

  // Increase the size of arr by reallocating memory
  stt->arr = realloc(stt->arr, (stt->count + 1) * sizeof(struct str_id*));
  
  if (stt->arr == NULL) {
    // Handle allocation failure
    return;
  }

  // Allocate memory for the new struct str_id
  stt->arr[stt->count] = malloc(sizeof(struct str_id));
  if (stt->arr[stt->count] == NULL) {
    // Handle allocation failure
    return;
  }

  // Set the values for the new struct str_id
  stt->arr[stt->count]->id = id;
  stt->arr[stt->count]->s = strdup(s); // Using strdup to duplicate the string

  if (stt->arr[stt->count]->s == NULL) {
    // Handle allocation failure
    free(stt->arr[stt->count]); // Free the allocated struct str_id
    return;
  }

  stt->count++;
}

void symbol_table_destroy(struct symbol_table *stt) {
  if (stt == NULL) {
    return;
  }

  // Free memory allocated for each struct str_id and its string
  for (int i = 0; i < stt->count; i++) {
    free(stt->arr[i]->s);
    free(stt->arr[i]);
  }

  // Free the array of struct str_id pointers and the symbol_table itself
  free(stt->arr);
  free(stt);
}

int main() {
  struct symbol_table *stt = symbol_table_create();

  symbol_table_add(stt, "sym1", 1);
  symbol_table_add(stt, "sym2", 2);
  symbol_table_add(stt, "sym3", 3);

  // Access the elements in stt
  for (int i = 0; i < stt->count; i++) {
    printf("Symbol: %s, ID: %d\n", stt->arr[i]->s, stt->arr[i]->id);
  }

  symbol_table_destroy(stt);

  return 0;
}
