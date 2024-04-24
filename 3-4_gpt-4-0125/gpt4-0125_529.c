#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct str_id {
    char* s;
    int id;
};

struct symbol_table {
    int count;
    struct str_id** arr; // Pointer to an array of pointer to str_id
};

struct symbol_table* symbol_table_create(void) {
    struct symbol_table *stt = malloc(sizeof(struct symbol_table));
    if (stt == NULL) {
        return NULL; // Always check if malloc was successful
    }
    stt->count = 0; // Start with count 0, we haven't added any symbols yet
    stt->arr = NULL; // Initialize to NULL as we have no elements at creation time
    return stt;
}

// Function to add a symbol to the table
int symbol_table_add(struct symbol_table *stt, const char* s, int id) {
    // Reallocate the array to accommodate one more pointer
    struct str_id** newArr = realloc(stt->arr, (stt->count + 1) * sizeof(struct str_id*));
    if (newArr == NULL) {
        return -1; // Reallocation failed
    }
    stt->arr = newArr;
    // Allocate memory for new symbol
    struct str_id* newSymbol = malloc(sizeof(struct str_id));
    if (newSymbol == NULL) {
        return -1; // Allocation failed
    }
    newSymbol->s = strdup(s); // Duplicate the string to ensure it's safely stored
    newSymbol->id = id;
    // Point the last element of the array to the new symbol
    stt->arr[stt->count] = newSymbol;
    stt->count += 1;
    return 0; // Success
}

// Just for demonstration: a simple function to print the symbol table contents
void symbol_table_print(struct symbol_table* stt) {
    for (int i = 0; i < stt->count; i++) {
        printf("{ \"%s\", %d }\n", stt->arr[i]->s, stt->arr[i]->id);
    }
}

// For Cleanup
void symbol_table_destroy(struct symbol_table *stt) {
    for (int i = 0; i < stt->count; i++) {
        free(stt->arr[i]->s); // Free duplicated string
        free(stt->arr[i]); // Free str_id structs
    }
    free(stt->arr); // Free array of pointers
    free(stt); // Free the symbol table itself
}

int main() {
    struct symbol_table* myTable = symbol_table_create();
    symbol_table_add(myTable, "sym1", 1);
    symbol_table_add(myTable, "sym2", 2);
    symbol_table_add(myTable, "sym3", 3);
    
    symbol_table_print(myTable);
    symbol_table_destroy(myTable);
    
    return 0;
}
