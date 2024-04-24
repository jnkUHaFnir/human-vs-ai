int add_symbol(symbol* new_symbol, int* count) {
    if (*count == SIZE) {
        // Reallocate more memory for the symbol_Table array
        symbol** temp = realloc(symbol_Table, 2 * SIZE * sizeof(symbol*));
        if (temp == NULL) {
            // Handle reallocation failure
            return -1; // Return an error code
        }
        symbol_Table = temp;
        SIZE *= 2; // Update the global SIZE variable
    }

    symbol_Table[*count] = malloc(sizeof(symbol));
    symbol_Table[*count]->action = new_symbol->action;
    symbol_Table[*count]->external = new_symbol->external;
    symbol_Table[*count]->address = new_symbol->address;
    strcpy(symbol_Table[*count]->label, new_symbol->label);
    symbol_Table[*count]->data_flag = new_symbol->data_flag;

    return ++(*count);
}
typedef struct symbol_node {
    symbol* data;
    struct symbol_node* next;
} symbol_node;

symbol_node* symbol_Head = NULL;

void add_symbol(symbol* new_symbol) {
    symbol_node* new_node = (symbol_node*)malloc(sizeof(symbol_node));
    new_node->data = new_symbol;
    new_node->next = NULL;

    if (symbol_Head == NULL) {
        symbol_Head = new_node;
    } else {
        symbol_node* current = symbol_Head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}
