symbol **symbol_Table = NULL;  // Declare as a pointer to pointer to symbol
int max_size = INITIAL_SIZE;   // Start with some initial size
int count = 0;                 // Keep track of the current number of symbols

// When you need to add a new symbol:
if (count >= max_size) {
    max_size *= 2;  // Decide on your array growth factor (e.g., double the size)
    symbol_Table = realloc(symbol_Table, max_size * sizeof(symbol*));
    if (!symbol_Table) {
        perror("Failed to reallocate symbol table");
        exit(EXIT_FAILURE);
    }
}
// Else, simply add your symbol to the table as before
