// Allocate initial memory for the pointer to pointers
symbol **symbol_Table = malloc(SIZE * sizeof(symbol *));

// When you need to reallocate, do this:
unsigned newSize = oldSize * 2; // Example: double the size
symbol **temp = realloc(symbol_Table, newSize * sizeof(symbol *));
if (!temp) {
    // Handle error (not enough memory)
} else {
    symbol_Table = temp;
}
