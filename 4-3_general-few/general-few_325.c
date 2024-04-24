if (count == SIZE){
    SIZE *= 2; // Double the size of the array
    symbol_Table = realloc(symbol_Table, SIZE * sizeof(symbol *));
    if (symbol_Table == NULL) {
        // Handle realloc failure
    }
}
