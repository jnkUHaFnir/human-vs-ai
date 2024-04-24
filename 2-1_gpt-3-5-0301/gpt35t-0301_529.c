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

struct symbol_table* symbol_table_create(int count) {
  struct symbol_table* stt = malloc(sizeof(struct symbol_table));
  stt->count = count;
  stt->arr = malloc(sizeof(struct str_id) * count);
  for (int i = 0; i < count; i++) {
    stt->arr[i].s = malloc(sizeof(char) * 20); // Allocate space for a string up to 19 characters long, plus 1 for the null terminator
    stt->arr[i].id = 0;
  }
  return stt;
}

void symbol_table_destroy(struct symbol_table* stt) {
  for (int i = 0; i < stt->count; i++) {
    free(stt->arr[i].s);
  }
  free(stt->arr);
  free(stt);
}

int main() {
  struct symbol_table* stt = symbol_table_create(3);
  strcpy(stt->arr[0].s, "sym1");
  stt->arr[0].id = 1;
  strcpy(stt->arr[1].s, "sym2");
  stt->arr[1].id = 2;
  strcpy(stt->arr[2].s, "sym3");
  stt->arr[2].id = 3;
  // do something with stt...
  symbol_table_destroy(stt);
  return 0;
}
