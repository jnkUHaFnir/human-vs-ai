#include <stdlib.h>
#include <string.h>

// Typedef to improve readability and avoid writing 'struct' everywhere
typedef struct {
  char *s;
  int id;
} str_id;

typedef struct {
  int count;
  str_id **arr; // Remove struct keyword, since we use typedef
} symbol_table;

// Create a new str_id and pass the values
str_id *str_id_create(const char *s, int id) {
  str_id *new_str_id = malloc(sizeof(str_id));
  new_str_id->s = strdup(s); // Copy the string content, instead of just the pointer
  new_str_id->id = id;
  return new_str_id;
}

symbol_table *symbol_table_create(void) {
  symbol_table *stt = malloc(sizeof(symbol_table));
  stt->count = 1;
  stt->arr = malloc(sizeof(str_id *) * stt->count);
  
  // Initialize the array elements with your desired values
  stt->arr[0] = str_id_create("sym1", 1);
  
  return stt;
}
void symbol_table_add(symbol_table *stt, const char *s, int id) {
  stt->count++;
  stt->arr = realloc(stt->arr, sizeof(str_id *) * stt->count); // Resize the array
  stt->arr[stt->count - 1] = str_id_create(s, id); // Add the new element
}
void symbol_table_destroy(symbol_table *stt) {
  for (int i = 0; i < stt->count; i++) {
    free(stt->arr[i]->s); // Free the string memory
    free(stt->arr[i]);     // Free the str_id memory
  }
  free(stt->arr); // Free the array memory
  free(stt);      // Free the symbol_table memory
}
