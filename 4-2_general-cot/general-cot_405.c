void reset_symbol_table() {
    for (int i = 0; i < SIZE; i++) {
        if (symbol_Table[i] != NULL) {
            free(symbol_Table[i]);
            symbol_Table[i] = NULL;
        }
    }
}
int add_symbol(symbol *new_symbol, int *count) {
    if (*count == SIZE) {
        // Perform reallocation when the array is full
        // Here we double the current size
        int new_size = SIZE * 2;
        symbol **tmp = realloc(symbol_Table, new_size * sizeof(symbol *));
        if (tmp == NULL) {
            // Handle allocation failure
            // For now, we will just return the current count
            return *count;
        }
        symbol_Table = tmp;
        SIZE = new_size;
    }

    symbol_Table[*count] = malloc(sizeof(symbol));
    if (symbol_Table[*count] == NULL) {
        // Handle allocation failure
        return *count;
    }

    symbol_Table[*count]->action = new_symbol->action;
    symbol_Table[*count]->external = new_symbol->external;
    symbol_Table[*count]->address = new_symbol->address;
    strcpy(symbol_Table[*count]->label, new_symbol->label);
    symbol_Table[*count]->data_flag = new_symbol->data_flag;

    return ++(*count);
}
