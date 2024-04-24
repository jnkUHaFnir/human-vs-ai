for (i = 0; i < count; i++) {
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
    symbol_Table[i] = malloc(sizeof(symbol));
    symbol_Table[i]->action = 0;
    symbol_Table[i]->external = 0;
    symbol_Table[i]->address = 0;
    symbol_Table[i]->label[0] = '\0';
    symbol_Table[i]->data_flag = 0;
}
int add_symbol(symbol *new_symbol, int count) {
    if (count == SIZE) {
        // Reallocate more memory
        symbol **new_symbol_Table = realloc(symbol_Table, sizeof(symbol *) * (SIZE + 10));
        if (new_symbol_Table == NULL) {
            fprintf(stderr, "Failed to allocate memory\n");
            exit(EXIT_FAILURE);
        }
        symbol_Table = new_symbol_Table;
        SIZE += 10;
    }
    symbol_Table[count] = malloc(sizeof(symbol));
    symbol_Table[count]->action = new_symbol->action;
    symbol_Table[count]->external = new_symbol->external;
    symbol_Table[count]->address = new_symbol->address;
    strcpy(symbol_Table[count]->label, new_symbol->label);
    symbol_Table[count]->data_flag = new_symbol->data_flag;

    return count + 1;
}
