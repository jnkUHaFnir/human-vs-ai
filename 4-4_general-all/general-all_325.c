int i;
for(i = 0; i < count; i++) {
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
}
#define INITIAL_SIZE 30
#define SIZE_INCREMENT 10

int count = 0;
int capacity = INITIAL_SIZE;

// Function to add a new symbol to the symbol table
void add_symbol(symbol *new_symbol) {
    if (count == capacity) {
        capacity += SIZE_INCREMENT;
        symbol **temp = realloc(symbol_Table, capacity * sizeof(symbol*));
        if (temp == NULL) {
            // Handle realloc failure
            // It's important to not lose the current symbols if realloc fails
            // You can free the new_symbol here as it won't be added
            free(new_symbol);
            return;
        }
        symbol_Table = temp;
    }

    symbol_Table[count] = malloc(sizeof(symbol));
    symbol_Table[count]->action = new_symbol->action;
    symbol_Table[count]->external = new_symbol->external;
    symbol_Table[count]->address = new_symbol->address;
    strcpy(symbol_Table[count]->label, new_symbol->label);
    symbol_Table[count]->data_flag = new_symbol->data_flag;

    count++;
}
