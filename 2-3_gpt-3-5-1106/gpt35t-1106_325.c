if (count == SIZE) {
    symbol_Table = realloc(symbol_Table, SIZE * 2 * sizeof(symbol*)); // Double the size of the array
    // Check if realloc was successful
    if (symbol_Table == NULL) {
        // Handle error
    } else {
        SIZE *= 2; // Update the maximum size
    }
}
