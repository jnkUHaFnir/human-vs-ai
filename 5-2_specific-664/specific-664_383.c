// Free all the symbol structs
for(i = 0; i < count ; i++){
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
}

// Free the symbol_Table array itself
free(symbol_Table);
symbol_Table = NULL;
void add_symbol(symbol *new_symbol, int *count, int *size){
    if(*count == *size) {
        *size *= 2; // Double the size (you can choose a different strategy)
        symbol **temp = realloc(symbol_Table, *size * sizeof(symbol*));
        if (temp == NULL) {
            // Handle allocation failure
            // For example, print an error message and exit the program
            printf("Memory reallocation failed. Exiting...\n");
            exit(EXIT_FAILURE);
        }
        symbol_Table = temp;
    }

    // Add the new symbol to the table
    symbol_Table[*count] = malloc(sizeof(symbol));
    // Copy symbol fields here as you were doing before

    // Increment count for the next symbol
    (*count)++;
}
