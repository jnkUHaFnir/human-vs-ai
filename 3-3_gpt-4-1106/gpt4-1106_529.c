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

// Function to create a symbol table
struct symbol_table *symbol_table_create(void) {
  struct symbol_table *stt = malloc(sizeof(struct symbol_table));
  if (!stt) {
    // Handle memory allocation failure
    return NULL;
  }
  stt->count = 0;
  stt->arr = NULL; // Start with no entries
  return stt;
}

// Function to add a symbol to the table
int symbol_table_add(struct symbol_table *stt, const char *sym, int id) {
  struct str_id *new_entry = malloc(sizeof(struct str_id));
  if (!new_entry) {
    // Handle memory allocation failure
    return -1;
  }
  new_entry->s = strdup(sym); // Copy the string into the str_id struct
  new_entry->id = id;

  // Resize the array to hold the new entry
  struct str_id **new_arr = realloc(stt->arr, sizeof(struct str_id*) * (stt->count + 1));
  if (!new_arr) {
    // Handle memory allocation failure
    free(new_entry->s); // Free the copied string
    free(new_entry); // Free the allocated str_id
    return -1;
  }
  stt->arr = new_arr;
  stt->arr[stt->count] = new_entry; // Add the new entry to the array
  stt->count++;

  return 0;
}

// Remember to free the symbol table when you're done using it
void symbol_table_destroy(struct symbol_table *stt) {
  if (stt) {
    for (int i = 0; i < stt->count; ++i) {
      free(stt->arr[i]->s);
      free(stt->arr[i]);
    }
    free(stt->arr);
    free(stt);
  }
}

int main() {
  // Usage example
  struct symbol_table *st = symbol_table_create();

  symbol_table_add(st, "sym1", 1);
  symbol_table_add(st, "sym2", 2);
  symbol_table_add(st, "sym3", 3);

  // do something with the symbol table...

  symbol_table_destroy(st); // Clean up the symbol table
  return 0;
}
