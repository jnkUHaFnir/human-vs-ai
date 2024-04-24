#include <stdio.h>
#include <stdlib.h>

struct str_id {
  char* s;
  int id;
};
  
struct symbol_table {
  int count;
  struct str_id** arr; // Array of pointers to struct str_id
};

struct symbol_table *symbol_table_create(int count) {
  struct symbol_table *stt = malloc(sizeof(struct symbol_table));
  if (!stt) {
    // Always check if malloc was successful
    return NULL;
  }
  
  stt->count = count;
  // Allocate memory for `count` pointers to struct str_id
  stt->arr = malloc(sizeof(struct str_id*) * count);
  if (!stt->arr) {
    // Check for allocation failure
    free(stt);
    return NULL;
  }

  // Initialize array elements to NULL
  for (int i = 0; i < count; i++) {
    stt->arr[i] = NULL;
  }
  
  return stt;
}
// Function to add a symbol to the symbol_table
// Note: Proper error handling and checks should be added as needed
void symbol_table_insert(struct symbol_table* st, int index, char* symbol, int id) {
  if (index < 0 || index >= st->count) {
    // Index out of bounds
    return;
  }
  
  // Allocate and initialize str_id struct
  struct str_id* newId = malloc(sizeof(struct str_id));
  newId->s = symbol;  // In real scenario, you may want to duplicate the string
  newId->id = id;
  
  // Add to the array
  st->arr[index] = newId;
}
