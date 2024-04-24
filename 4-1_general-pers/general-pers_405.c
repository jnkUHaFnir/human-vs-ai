memset(new_symbol, 0, sizeof(symbol));
#include <stdlib.h>
#include <string.h>

void clear_symbol(symbol *sym) {
    memset(sym, 0, sizeof(symbol));
}

void reset_symbol_table() {
    for (int i = 0; i < SIZE; i++) {
        if (symbol_Table[i] != NULL) {
            free(symbol_Table[i]);
            symbol_Table[i] = NULL;
        }
    }
}

void resize_symbol_table() {
    SIZE *= 2; // Double the size for example
    symbol **new_symbol_Table = malloc(SIZE * sizeof(symbol *));
    if (new_symbol_Table == NULL) {
        // Handle allocation failure
    }
    
    // Copy existing symbols to new table
    for (int i = 0; i < SIZE / 2; i++) {
        new_symbol_Table[i] = symbol_Table[i];
        symbol_Table[i] = NULL; // Set old pointers to NULL to avoid double free
    }

    // Free old table
    free(symbol_Table);

    // Update global symbol table pointer
    symbol_Table = new_symbol_Table;
}

// Example usage after reading the first file
// Reset count and clear symbol table for reuse
count = 0;
reset_symbol_table();

// Read the second file and populate symbol table

// Example usage when resizing is needed
if (count == SIZE) {
    resize_symbol_table();
}
