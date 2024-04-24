// Declare your symbol table like this (initially set to NULL):
symbol **symbol_Table = NULL;
int size = SIZE;

// In your add_symbol function:
if(count == size){
    size *= 2; // make the new size double the old size
    symbol_Table = realloc(symbol_Table, size * sizeof(symbol *));
    if (!symbol_Table) {
        // handle error, for example: "Memory allocation failed.\n"
        exit(1);
    }
}

// Rest of your add_symbol function remains the same.
