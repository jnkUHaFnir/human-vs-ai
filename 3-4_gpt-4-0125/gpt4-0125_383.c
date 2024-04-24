symbol **symbol_Table = NULL;
int table_capacity = SIZE; // Initial capacity.
if (count == table_capacity) {
    table_capacity *= 2; // Double the capacity, for example.
    symbol_Table = realloc(symbol_Table, table_capacity * sizeof(symbol*));
    if (symbol_Table == NULL) {
        // Handle error: memory allocation failed.
    }
}
symbol_Table = malloc(table_capacity * sizeof(symbol*));
if (symbol_Table == NULL) {
    // Handle error: memory allocation failed.
}
