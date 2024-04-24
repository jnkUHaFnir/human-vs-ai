int i;
for (i = 0; i < count; i++) {
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
}
void add_symbol(symbol* new_symbol) {
    if (count == SIZE) {
        // Reallocate more memory to increase the size of the array
        symbol** temp = realloc(symbol_Table, 2 * SIZE * sizeof(symbol*));
        if (temp == NULL) {
            // Handle reallocation failure
            // e.g., print an error message and exit
            printf("Memory reallocation failed.");
            exit(1);
        }
        symbol_Table = temp;
        SIZE *= 2;  // Update the global SIZE value
    }

    // Add the new symbol to the table
    symbol_Table[count] = malloc(sizeof(symbol));
    symbol_Table[count]->action = new_symbol->action;
    symbol_Table[count]->external = new_symbol->external;
    symbol_Table[count]->address = new_symbol->address;
    strcpy(symbol_Table[count]->label, new_symbol->label);
    symbol_Table[count]->data_flag = new_symbol->data_flag;

    count++;
}
