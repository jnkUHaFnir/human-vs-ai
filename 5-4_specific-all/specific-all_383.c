#define SIZE 30
symbol *symbol_Table[SIZE];
int count = 0;

void add_symbol(symbol *new_symbol) {
    if (count == SIZE) {
        // Reallocate more memory
        symbol *new_symbol_Table[SIZE * 2]; // Double the size for example

        // Copy existing elements to the new array
        for (int i = 0; i < count; i++) {
            new_symbol_Table[i] = symbol_Table[i];
        }

        // Free the old array
        for (int i = 0; i < count; i++) {
            symbol_Table[i] = NULL; // reset the old pointers (not necessary for freeing)
            free(symbol_Table[i]);
        }

        // Update the symbol_Table to point to the new array
        memcpy(symbol_Table, new_symbol_Table, sizeof(symbol_Table));

        // Add the new symbol
        symbol_Table[count] = new_symbol;
        count++;
    } else {
        // Your existing logic to add a symbol if there is space in the array
        // Make sure to update `symbol_Table` and `count` accordingly
    }
}
