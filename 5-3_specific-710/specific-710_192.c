#define SIZE 30

void add_symbol(symbol* new_symbol, int* count) {
    if (*count == SIZE) {
        SIZE *= 2; // Double the size for reallocation
        symbol** temp = realloc(symbol_Table, SIZE * sizeof(symbol*));
        if (temp == NULL) {
            // Handle allocation failure
            // Print an error message or exit the program
        } else {
            symbol_Table = temp;
        }
    }
    
    symbol_Table[*count] = malloc(sizeof(symbol));
    symbol_Table[*count]->action = new_symbol->action;
    symbol_Table[*count]->external = new_symbol->external;
    symbol_Table[*count]->address = new_symbol->address;
    strcpy(symbol_Table[*count]->label, new_symbol->label);
    symbol_Table[*count]->data_flag = new_symbol->data_flag;
    
    (*count)++;
}
