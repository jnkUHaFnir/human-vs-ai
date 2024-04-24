if(count == SIZE){
    SIZE *= 2; // Double the size
    symbol_Table = realloc(symbol_Table, SIZE * sizeof(symbol*));
    if(symbol_Table == NULL){
        // handle allocation error
    }
}
