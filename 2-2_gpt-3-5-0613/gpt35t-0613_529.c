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
  stt->count = 3;
  stt->arr = malloc(sizeof(struct str_id) * stt->count);

  // Initialize the elements of stt->arr
  stt->arr[0].s = malloc(sizeof(char) * (strlen("sym1") + 1));
  strcpy(stt->arr[0].s, "sym1");
  stt->arr[0].id = 1;

  stt->arr[1].s = malloc(sizeof(char) * (strlen("sym2") + 1));
  strcpy(stt->arr[1].s, "sym2");
  stt->arr[1].id = 2;

  stt->arr[2].s = malloc(sizeof(char) * (strlen("sym3") + 1));
  strcpy(stt->arr[2].s, "sym3");
  stt->arr[2].id = 3;

  return stt;
}

int main() {
  struct symbol_table *st = symbol_table_create();
  
  // Print symbol table
  for (int i = 0; i < st->count; i++) {
    printf("{ \"%s\", %d }\n", st->arr[i].s, st->arr[i].id);
  }

  // Free memory
  for (int i = 0; i < st->count; i++) {
    free(st->arr[i].s);
  }
  free(st->arr);
  free(st);

  return 0;
}
