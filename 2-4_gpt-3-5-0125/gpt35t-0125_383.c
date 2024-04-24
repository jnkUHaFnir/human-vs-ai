if (count == SIZE) {
    symbol_Table = realloc(symbol_Table, SIZE * 2 * sizeof(symbol *));
    // Check if realloc was successful
    if (symbol_Table == NULL) {
        // Handle error - realloc failed
    }
    SIZE *= 2;
}
