for(i = 0; i < count ; i++){
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
}
count = 0; // Reset the symbol count after freeing all symbols
void add_symbol(symbol *new_symbol, int *count, int *capacity) {
    if (*count >= *capacity) {
        *capacity = *capacity * 2; // Double the capacity (resize strategy)
        symbol **temp = realloc(symbol_Table, *capacity * sizeof(symbol*));
        if (temp == NULL) {
            // Handle allocation failure
            // e.g., print an error message and exit or return an error code
        } else {
            symbol_Table = temp;
        }
    }
    
    symbol_Table[*count] = malloc(sizeof(symbol));
    symbol_Table[*count]->action = new_symbol->action;
    symbol_Table[*count]->external = new_symbol->external;
    symbol_Table[*count]->address = new_symbol->address;
    strcpy(symbol_Table[*count]->label, new_symbol->label);
    symbol_Table[*count]->data_flag = new_symbol->data_flag;
    
    (*count)++;
}
