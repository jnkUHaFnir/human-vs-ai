for(i = 0; i < count ; i++){
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
}
void add_symbol(symbol *new_symbol, int *count, int *capacity) {
    if (*count >= *capacity) {
        *capacity *= 2; // Double the capacity
        symbol **new_table = realloc(symbol_Table, *capacity * sizeof(symbol*));
        if (!new_table) {
            // Handle realloc failure
            // e.g., print an error message and exit
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
        symbol_Table = new_table;
    }

    symbol_Table[*count] = new_symbol;
    (*count)++;
}
