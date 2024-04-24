// Global declaration
size_t SIZE = 30; // Initial size of the array
size_t count = 0;
symbol **symbol_Table;

// Initialization
symbol_Table = malloc(sizeof(symbol *) * SIZE);

// Modifying adding function for reallocating
if (count == SIZE) {
    SIZE *= 2; // Double the size
    symbol_Table = realloc(symbol_Table, sizeof(symbol *) * SIZE);
    if (symbol_Table == NULL) {
        // Handle realloc failure
    }
}

if (count < SIZE) {
    symbol_Table[count] = malloc(sizeof(symbol));
    symbol_Table[count]->action = new_symbol->action;
    symbol_Table[count]->external = new_symbol->external;
    symbol_Table[count]->address = new_symbol->address;
    strcpy(symbol_Table[count]->label, new_symbol->label);
    symbol_Table[count]->data_flag = new_symbol->data_flag;

    return ++count;
}

// Freeing memory at the end
int i;
for (i = 0; i < count; i++) {
    free(symbol_Table[i]);
}
free(symbol_Table); // Don't forget to free the array itself

// Setting the array to NULL after freeing is not necessary anymore
