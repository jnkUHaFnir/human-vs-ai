if(count == SIZE) {
    symbol **temp = realloc(symbol_Table, SIZE * 2 * sizeof(symbol *));
    if(temp == NULL) {
        // Handle realloc failure
    } else {
        symbol_Table = temp;
        SIZE *= 2;
    }
}
