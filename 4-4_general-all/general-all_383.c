int i;
for(i = 0; i < count ; i++){
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
}
int add_symbol(symbol *new_symbol, int *count) {
    if (*count == SIZE) {
        // Reallocate memory to increase the size of the array
        symbol **temp = realloc(symbol_Table, 2 * SIZE * sizeof(symbol*));
        if (temp == NULL) {
            // Handle realloc error
            fprintf(stderr, "Error: Unable to reallocate memory\n");
            return -1; // indicate failure
        }
        symbol_Table = temp;
        SIZE *= 2; // Update the global SIZE variable
    }

    symbol_Table[*count] = malloc(sizeof(symbol));
    // Copy the symbol data
    symbol_Table[*count]->action = new_symbol->action;
    symbol_Table[*count]->external = new_symbol->external;
    symbol_Table[*count]->address = new_symbol->address;
    strcpy(symbol_Table[*count]->label, new_symbol->label);
    symbol_Table[*count]->data_flag = new_symbol->data_flag;

    printf("Added symbol: %s\n", new_symbol->label);

    // Increment the count
    (*count)++;

    return 0; // indicate success
}
