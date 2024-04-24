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
  stt->count = 3; // set initial count
  stt->arr = malloc(sizeof(struct str_id*) * stt->count);

  // Allocating memory for each element in the array
  for (int i = 0; i < stt->count; i++) {
    stt->arr[i] = malloc(sizeof(struct str_id));
    stt->arr[i]->s = malloc(20); // Allocating memory for the string (adjust size as needed)
    stt->arr[i]->id = i+1; // Assigning an ID
    sprintf(stt->arr[i]->s, "sym%d", i+1); // Assigning a symbol name
  }

  return stt;
}

int main() {
  struct symbol_table *st = symbol_table_create();

  for (int i = 0; i < st->count; i++) {
    printf("{ \"%s\", %d } \n", st->arr[i]->s, st->arr[i]->id);
  }

  // Freeing memory
  for (int i = 0; i < st->count; i++) {
    free(st->arr[i]->s);
    free(st->arr[i]);
  }
  free(st->arr);
  free(st);

  return 0;
}
