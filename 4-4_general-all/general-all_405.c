// Free the memory for each symbol and set the pointer to NULL
for(i = 0; i < count; i++){
    if(symbol_Table[i] != NULL){
        free(symbol_Table[i]);
        symbol_Table[i] = NULL;
    }
}
if(count == SIZE){
    // Calculate new size, for example, double the current size
    int new_size = SIZE * 2;
    
    // Reallocate memory for the symbol table
    symbol **new_symbol_Table = realloc(symbol_Table, new_size * sizeof(symbol *));
    
    if(new_symbol_Table != NULL){
        // Update the global pointer to the newly allocated memory
        symbol_Table = new_symbol_Table;
    }
    else {
        // Handle realloc failure
        // Print an error message, free existing memory, etc.
    }
}
