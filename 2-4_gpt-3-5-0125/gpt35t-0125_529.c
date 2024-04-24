#include <stdio.h>
#include <stdlib.h>

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
    stt->count = 3; // Set the initial count to 3 for your example
    stt->arr = malloc(sizeof(struct str_id) * stt->count);

    // Add your actual symbol table entries here based on your example
    stt->arr[0].s = "sym1";
    stt->arr[0].id = 1;
    stt->arr[1].s = "sym2";
    stt->arr[1].id = 2;
    stt->arr[2].s = "sym3";
    stt->arr[2].id = 3;

    return stt;
}

int main(void) {
    struct symbol_table *stt = symbol_table_create();

    // Output the symbol table entries
    for (int i = 0; i < stt->count; i++) {
        printf("{ \"%s\", %d }\n", stt->arr[i].s, stt->arr[i].id);
    }

    // Don't forget to free the memory allocated
    free(stt->arr);
    free(stt);

    return 0;
}
