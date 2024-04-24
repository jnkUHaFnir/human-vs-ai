#include <stdio.h>
#include <stdlib.h>
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
  stt->arr =  malloc(sizeof(struct str_id) * stt->count);
  return stt;
}

int main(void) {
  struct symbol_table* table = symbol_table_create();

  // Accessing and modifying the elements in the arr array
  table->arr[0].s = "sym1";
  table->arr[0].id = 1;
  table->arr[1].s = "sym2";
  table->arr[1].id = 2;
  table->arr[2].s = "sym3";
  table->arr[2].id = 3;

  // Testing the result
  for (int i = 0; i < table->count; i++) {
    printf("Symbol: %s, ID: %d\n", table->arr[i].s, table->arr[i].id);
  }

  // Cleanup
  free(table->arr);
  free(table);

  return 0;
}
