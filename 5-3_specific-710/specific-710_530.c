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
  stt->count = 3; // Set the initial count to 3
  stt->arr = malloc(sizeof(struct str_id*) * stt->count);

  // Allocate memory for each struct str_id element and initialize the strings
  for (int i = 0; i < stt->count; i++) {
    stt->arr[i] = malloc(sizeof(struct str_id));
    stt->arr[i]->s = malloc(strlen("symX") + 1); // +1 for the null terminator
    sprintf(stt->arr[i]->s, "sym%d", i+1); // Assign sym1, sym2, sym3 to each string
    stt->arr[i]->id = i+1; // Assign id values 1, 2, 3
  }

  return stt;
}

int main() {
  struct symbol_table *stt = symbol_table_create();

  for (int i = 0; i < stt->count; i++) {
    printf("{ \"%s\", %d }\n", stt->arr[i]->s, stt->arr[i]->id);
  }

  // Free the allocated memory
  for (int i = 0; i < stt->count; i++) {
    free(stt->arr[i]->s);
    free(stt->arr[i]);
  }
  free(stt->arr);
  free(stt);

  return 0;
}
