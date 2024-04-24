#include <stdio.h>
#include <stdlib.h>

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

  stt->arr[0].s = "sym1";
  stt->arr[0].id = 1;

  stt->arr[1].s = "sym2";
  stt->arr[1].id = 2;

  stt->arr[2].s = "sym3";
  stt->arr[2].id = 3;

  return stt;
}

int main() {
  struct symbol_table* st = symbol_table_create();

  for (int i = 0; i < st->count; i++) {
    printf("{ \"%s\", %d } ", st->arr[i].s, st->arr[i].id);
    if (i < st->count - 1) {
      printf(", ");
    }
  }

  free(st->arr);
  free(st);

  return 0;
}
