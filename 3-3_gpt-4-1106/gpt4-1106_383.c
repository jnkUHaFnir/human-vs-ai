// In your header or globally
int symbol_table_size = SIZE;
symbol **symbol_Table = malloc(sizeof(symbol *) * symbol_table_size);

// In the add_symbol function
if (count >= symbol_table_size) {
    // Increase the symbol_table_size
    symbol_table_size *= 2; // Double the size, as an example
    symbol **temp = realloc(symbol_Table, sizeof(symbol *) * symbol_table_size);
    if (!temp) {
        // Handle the allocation failure (possibly free everything and exit)
        // ...
    }
    symbol_Table = temp;
}

// Continue adding new elements
// ...

// In the end, when freeing
for (int i = 0; i < count; i++) {
    free(symbol_Table[i]);
    symbol_Table[i] = NULL; // It's good practice to set the pointer to NULL after freeing
}
free(symbol_Table); // Don't forget to free the symbol table itself
symbol_Table = NULL; // And make the pointer NULL

// Remember to reset count for next usage
count = 0;
