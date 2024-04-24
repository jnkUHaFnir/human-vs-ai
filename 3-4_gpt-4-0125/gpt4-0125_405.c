symbol **symbol_Table = NULL; // Note: It now points to NULL initially.
size_t symbol_Table_Size = SIZE; // Initial size
size_t count = 0; // Count of used entries
if (count == symbol_Table_Size) {
    size_t newSize = symbol_Table_Size * 2; // Example: Double the size
    symbol **newTable = realloc(symbol_Table, newSize * sizeof(symbol*));
    if (newTable == NULL) {
        // Handle memory allocation failure (e.g., by exiting or freeing existing resources)
        exit(1);
    }
    // Update table pointer and size on successful allocation
    symbol_Table = newTable;
    symbol_Table_Size = newSize;
}

// Now you continue to add the new symbol as before
symbol_Table[count] = malloc(sizeof(symbol));
// Populate symbol_Table[count]...
count++;
