void cleanup_symbol_table() {
    int i;
    for(i = 0; i < SIZE; i++){
        if(symbol_Table[i] != NULL) {
            free(symbol_Table[i]);
            symbol_Table[i] = NULL;
        }
    }
}
void add_symbol(symbol *new_symbol, int *count) {
    if(*count == SIZE) {
        SIZE *= 2; // double the size
        symbol_Table = realloc(symbol_Table, SIZE * sizeof(symbol*));
    }
    // ... rest of the function stays the same
}
