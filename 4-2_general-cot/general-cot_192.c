typedef struct symbol {
    unsigned action : 1;
    unsigned external : 1;
    int address;
    char label[SIZE];
    unsigned data_flag : 1;
} symbol;

symbol* symbol_Table[SIZE];
int count = 0;

void add_symbol(symbol* new_symbol) {
    if (count == SIZE) {
        // Handle the case when the array is full
        // You can implement a function to realloc the array here
        printf("Array is full\n");
        return;
    }

    symbol_Table[count] = new_symbol;
    count++;
}

void clear_symbols() {
    for (int i = 0; i < count; i++) {
        free(symbol_Table[i]);
        symbol_Table[i] = NULL;
    }
    count = 0; // Reset the count back to 0
}

int main() {
    // Reading and adding symbols to the symbol_Table array
    // Example:
    symbol* new_symbol = (symbol*)malloc(sizeof(symbol));
    
    // Populate new_symbol fields
    
    add_symbol(new_symbol);

    // Clearing the symbol_Table array when needed
    clear_symbols();
    
    // Reuse the symbol_Table array for new values

    return 0;
}
void extend_symbol_Table() {
    size_t new_size = 2 * SIZE; // Double the size of the array
    
    symbol** new_symbol_Table = (symbol**)realloc(symbol_Table, new_size * sizeof(symbol*));
    if (new_symbol_Table == NULL) {
        printf("Memory reallocation failed\n");
        return;
    }
    
    symbol_Table = new_symbol_Table;
    SIZE = new_size;
}
