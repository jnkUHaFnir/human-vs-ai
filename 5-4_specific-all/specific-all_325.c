for(i = 0; i < count ; i++){
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
}
count = 0; // Reset the count to 0 after freeing all elements
void add_symbol(symbol* new_symbol, int* count, int* size) {
    if (*count == *size) {
        *size *= 2; // Double the size of the array
        symbol** temp = realloc(symbol_Table, *size * sizeof(symbol*));
        if (temp == NULL) {
            // Handle realloc failure
            return;
        }
        symbol_Table = temp;
    }

    symbol_Table[*count] = malloc(sizeof(symbol));
    // Copy data from new_symbol to symbol_Table[*count]
    *count += 1; // Increment count
}
