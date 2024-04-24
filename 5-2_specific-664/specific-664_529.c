#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct str_id {
    char *s;
    int id;
};

struct symbol_table {
    int count;
    struct str_id *arr;
};

struct symbol_table *symbol_table_create(void) {
    struct symbol_table *stt = malloc(sizeof(struct symbol_table));
    if (stt == NULL) {
        // Handle allocation failure
        return NULL;
    }

    stt->count = 0;
    stt->arr = NULL;

    return stt;
}

void symbol_table_add(struct symbol_table *stt, const char *s, int id) {
    stt->count++;
    stt->arr = realloc(stt->arr, stt->count * sizeof(struct str_id));
    if (stt->arr == NULL) {
        // Handle reallocation failure
        return;
    }

    stt->arr[stt->count - 1].s = strdup(s);
    stt->arr[stt->count - 1].id = id;
}

void symbol_table_destroy(struct symbol_table *stt) {
    if (stt == NULL) {
        return;
    }

    for (int i = 0; i < stt->count; i++) {
        free(stt->arr[i].s);
    }

    free(stt->arr);
    free(stt);
}

int main() {
    struct symbol_table *stt = symbol_table_create();

    symbol_table_add(stt, "sym1", 1);
    symbol_table_add(stt, "sym2", 2);
    symbol_table_add(stt, "sym3", 3);

    for (int i = 0; i < stt->count; i++) {
        printf("{ \"%s\", %d }\n", stt->arr[i].s, stt->arr[i].id);
    }

    symbol_table_destroy(stt);

    return 0;
}
