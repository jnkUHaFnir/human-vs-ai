for(i = 0; i < count ; i++){
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
}
int add_symbol(symbol *new_symbol){
    int i;
    for(i = 0; i < SIZE ; i++){
        if(symbol_Table[i] == NULL){
            symbol_Table[i] = new_symbol;
            return i;
        }
    }
    // If no available memory slot, you can either return an error code or
    // allocate more memory using realloc. See the next point for details.
    return -1; // For example, -1 indicates an error.
}
int add_symbol(symbol *new_symbol){
    if(count >= SIZE){
        // Reallocate more memory to increase the size of the array.
        int new_size = SIZE * 2; // or any other desired size increase.
        symbol **new_table = realloc(symbol_Table, new_size * sizeof(symbol*));
        if(new_table == NULL){
            return -1; // Error in realloc.
        }
        symbol_Table = new_table;
        SIZE = new_size;
    }
    
    symbol_Table[count] = new_symbol;
    return ++count;
}
