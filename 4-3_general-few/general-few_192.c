#define INITIAL_SIZE 30

// Function to add a new symbol to the table
void add_symbol(symbol* new_symbol, int *count, int *size) {
    if (*count == *size) {
        *size *= 2;  // Double the size when reaching the limit
        symbol** new_table = realloc(symbol_Table, *size * sizeof(symbol*));
        if (new_table == NULL) {
            // Handle reallocation failure
            // Example: printf("Memory reallocation failed");
            return;
        }
        symbol_Table = new_table;
    }

    symbol_Table[*count] = malloc(sizeof(symbol));
    // Copy new_symbol data to symbol_Table[*count]

    (*count)++;
}

// Function to free all symbols in the table
void clear_symbols(int count) {
    for (int i = 0; i < count; i++) {
        free(symbol_Table[i]);
    }
}

// In your program
int main() {
    int count = 0;
    int size = INITIAL_SIZE;

    // Read files, add symbols, etc.

    // Clear symbols at the end
    clear_symbols(count);

    // Free the array itself
    free(symbol_Table);

    return 0;
}
