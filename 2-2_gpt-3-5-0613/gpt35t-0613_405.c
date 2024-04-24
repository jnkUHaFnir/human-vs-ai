for (int i = 0; i < SIZE; i++) {
    symbol_Table[i] = NULL;
}
#define GROW_SIZE 10

if (count == SIZE) {
    symbol** newTable = realloc(symbol_Table, (SIZE + GROW_SIZE) * sizeof(symbol*));
    if (newTable == NULL) {
        // Handle the case when realloc fails
        // Handle the error and free any allocated memory before exiting or returning
    } else {
        // Realloc succeeded, update the symbol_Table and SIZE
        symbol_Table = newTable;
        SIZE += GROW_SIZE;
    }
}
