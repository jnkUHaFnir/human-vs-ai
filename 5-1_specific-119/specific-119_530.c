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

struct symbol_table* symbol_table_create(void) {
  struct symbol_table* stt = malloc(sizeof(struct symbol_table));
  stt->count = 3; // Set the initial count to 3
  stt->arr = malloc(sizeof(struct str_id*) * stt->count);

  // Initialize each element in the array
  for (int i = 0; i < stt->count; i++) {
    stt->arr[i] = malloc(sizeof(struct str_id));
    stt->arr[i]->s = malloc(50 * sizeof(char)); // Allocate memory for a string of size 50
  }

  // Assign values to the array elements
  stt->arr[0]->s = "sym1";
  stt->arr[0]->id = 1;
  stt->arr[1]->s = "sym2";
  stt->arr[1]->id = 2;
  stt->arr[2]->s = "sym3";
  stt->arr[2]->id = 3;

  return stt;
}

int main() {
  struct symbol_table* st = symbol_table_create();

  // Print the values in the symbol table for demonstration
  for (int i = 0; i < st->count; i++) {
    printf("Symbol: %s, ID: %d\n", st->arr[i]->s, st->arr[i]->id);
  }

  return 0;
}
