// Increment to increase the size by.
#define INCREMENT_SIZE 10

// Reallocate the array to increase its size when it's full.
if (count == SIZE) {
    symbol **new_table = realloc(symbol_Table, (SIZE + INCREMENT_SIZE) * sizeof(symbol *));
    if (new_table) {
        // Realloc successful, update the symbol_Table pointer and SIZE.
        symbol_Table = new_table;
        SIZE += INCREMENT_SIZE;
        // Initialize the new elements to NULL.
        for (int i = count; i < SIZE; i++) {
            symbol_Table[i] = NULL;
        }
    } else {
        // Handle the error, realloc failed.
        // Do not change SIZE or the symbol_Table pointer.
        // Also, make sure you don't lose the original data in symbol_Table.
    }
}
