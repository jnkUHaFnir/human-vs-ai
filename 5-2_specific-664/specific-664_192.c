void clear_symbol_table() {
    int i;
    for(i = 0; i < SIZE; i++) {
        if(symbol_Table[i] != NULL) {
            free(symbol_Table[i]);
            symbol_Table[i] = NULL;
        }
    }
}
int add_symbol(symbol* new_symbol, int count) {
    if(count == SIZE) {
        SIZE *= 2; // Double the size or choose a different strategy
        symbol** temp = realloc(symbol_Table, SIZE * sizeof(symbol*));
        if(temp == NULL) {
            // Handle realloc failure
            return count;
        }
        symbol_Table = temp;
    }

    if(count < SIZE) {
        symbol_Table[count] = malloc(sizeof(symbol));
        if(symbol_Table[count] == NULL) {
            // Handle malloc failure
            return count;
        }
        symbol_Table[count]->action = new_symbol->action;
        symbol_Table[count]->external = new_symbol->external;
        symbol_Table[count]->address = new_symbol->address;
        strcpy(symbol_Table[count]->label, new_symbol->label);
        symbol_Table[count]->data_flag = new_symbol->data_flag;
        return count + 1;
    }

    return count;
}
