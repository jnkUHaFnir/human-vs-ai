#include <stdio.h>
#include <stdlib.h>

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
  stt->count = 3;
  stt->arr =  malloc(sizeof(struct str_id*) * stt->count);
  
  for (int i = 0; i < stt->count; i++) {
    stt->arr[i] = malloc(sizeof(struct str_id));
    stt->arr[i]->s = malloc(10 * sizeof(char)); // adjust the size as needed
  }
  
  stt->arr[0]->s = "sym1";
  stt->arr[0]->id = 1;
  stt->arr[1]->s = "sym2";
  stt->arr[1]->id = 2;
  stt->arr[2]->s = "sym3";
  stt->arr[2]->id = 3;
  
  return stt;
}

int main() {
  struct symbol_table *st = symbol_table_create();
  
  for (int i = 0; i < st->count; i++) {
    printf("{ \"%s\", %d }\n", st->arr[i]->s, st->arr[i]->id);
  }
  
  return 0;
}
