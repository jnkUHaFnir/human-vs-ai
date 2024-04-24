for (i = 0; i < count; i++) {
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
}
#define SIZE 30

symbol **symbol_Table = NULL;
int count = 0;
int capacity = 0;

void add_symbol(symbol *new_symbol) {
    if (count == capacity) {
        capacity += SIZE;
        symbol_Table = realloc(symbol_Table, capacity * sizeof(symbol*));
        if (symbol_Table == NULL) {
            // Handle realloc failure
        }
    }

    symbol_Table[count] = malloc(sizeof(symbol));
    symbol_Table[count]->action = new_symbol->action;
    symbol_Table[count]->external = new_symbol->external;
    symbol_Table[count]->address = new_symbol->address;
    strcpy(symbol_Table[count]->label, new_symbol->label);
    symbol_Table[count]->data_flag = new_symbol->data_flag;

    count++;
}
