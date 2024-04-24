int i;
for(i = 0; i < count; i++) {
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
}
count = 0; // Reset the count of elements in the array
void add_symbol(symbol *new_symbol) {
    if(count == SIZE) {
        SIZE *= 2;
        symbol **temp = realloc(symbol_Table, SIZE * sizeof(symbol *));
        if(temp == NULL) {
            // Handle realloc failure
            return;
        }
        symbol_Table = temp;
    }

    symbol_Table[count] = malloc(sizeof(symbol));
    // Copy new_symbol to symbol_Table[count]

    count++;
}
