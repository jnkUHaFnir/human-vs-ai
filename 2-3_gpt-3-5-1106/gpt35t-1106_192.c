if(count == SIZE){
    symbol_Table = realloc(symbol_Table, SIZE * 2 * sizeof(symbol*)); // Double the size of the array
    SIZE *= 2; // Update the value of SIZE
}
