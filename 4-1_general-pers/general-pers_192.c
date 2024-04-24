int add_symbol(symbol *new_symbol, int *count, int *max_size) {
    if (*count == *max_size) {
        *max_size *= 2;
        symbol **temp = realloc(symbol_Table, (*max_size) * sizeof(symbol*));
        if (temp == NULL) {
            // Handle memory reallocation failure
            return -1;
        }
        symbol_Table = temp;
    }

    symbol_Table[*count] = calloc(1, sizeof(symbol));

    // Copy new_symbol content to the symbol table
    symbol_Table[*count]->action = new_symbol->action;
    symbol_Table[*count]->external = new_symbol->external;
    symbol_Table[*count]->address = new_symbol->address;
    strcpy(symbol_Table[*count]->label, new_symbol->label);
    symbol_Table[*count]->data_flag = new_symbol->data_flag;

    (*count)++;

    return 0;
}
void clear_symbol_table(int *count) {
    for(int i = 0; i < *count; i++) {
        // Free memory for individual symbols
        free(symbol_Table[i]);
        symbol_Table[i] = NULL;
    }

    *count = 0;
}
typedef struct node {
    symbol data;
    struct node* next;
} node;
