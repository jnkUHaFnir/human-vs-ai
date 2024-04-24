for(i = 0; i < count; i++) {
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
}

count = 0; // Reset count
void add_symbol(symbol *new_symbol, int *count) {
    if (*count == SIZE) {
        // Reallocate the array to increase its size
        symbol **temp = realloc(symbol_Table, 2 * SIZE * sizeof(symbol *));
        if (temp == NULL) {
            // Handle reallocation failure
            // You can't continue, so exit or return an error
            exit(EXIT_FAILURE);
        } else {
            symbol_Table = temp;
            SIZE *= 2; // Update SIZE to the new size
        }
    }

    // Add the new symbol at the next index
    symbol_Table[*count] = malloc(sizeof(symbol));
    symbol_Table[*count]->action = new_symbol->action;
    symbol_Table[*count]->external = new_symbol->external;
    symbol_Table[*count]->address = new_symbol->address;
    strcpy(symbol_Table[*count]->label, new_symbol->label);
    symbol_Table[*count]->data_flag = new_symbol->data_flag;

    (*count)++;
}
