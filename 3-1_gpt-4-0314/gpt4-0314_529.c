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
    stt->count = 0;
    stt->arr = malloc(sizeof(struct str_id*) * 1);
    return stt;
}

void symbol_table_add(struct symbol_table *stt, const char *new_symbol, int new_id) {
    struct str_id *new_entry = malloc(sizeof(struct str_id));
    new_entry->s = strdup(new_symbol);
    new_entry->id = new_id;

    stt->count++;
    stt->arr = realloc(stt->arr, sizeof(struct str_id*) * stt->count);
    stt->arr[stt->count - 1] = new_entry;
}

void symbol_table_free(struct symbol_table *stt) {
    for (int i = 0; i < stt->count; ++i) {
        free(stt->arr[i]->s);
        free(stt->arr[i]);
    }
    free(stt->arr);
    free(stt);
}

int main() {
    struct symbol_table *st = symbol_table_create();
    symbol_table_add(st, "sym1", 1);
    symbol_table_add(st, "sym2", 2);
    symbol_table_add(st, "sym3", 3);

    // Your array can now be accessed via st->arr, like st->arr[0], st->arr[1], st->arr[2]

    symbol_table_free(st);
    return 0;
}
