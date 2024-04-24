if(count == SIZE){
    symbol_Table = realloc(symbol_Table, 2 * SIZE * sizeof(symbol*));
    SIZE *= 2;
}
