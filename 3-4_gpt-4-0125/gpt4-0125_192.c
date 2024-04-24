if (count >= SIZE) {
    int new_size = SIZE * 2; // Example: Double the size
    symbol **new_table = realloc(symbol_Table, new_size * sizeof(symbol*));
    if (new_table == NULL) {
        // Handle allocation failure
    } else {
        symbol_Table = new_table; // Update the reference if realloc was successful
        SIZE = new_size; // Update the size to reflect the new capacity
    }
}
