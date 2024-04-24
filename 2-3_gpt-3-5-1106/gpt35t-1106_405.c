if(count == SIZE){
    symbol_Table = realloc(symbol_Table, SIZE * 2 * sizeof(symbol*));
    SIZE *= 2; // Update the size of the array
}
