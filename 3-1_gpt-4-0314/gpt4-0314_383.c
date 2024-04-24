int i;
for(i = 0; i < count ; i++){
    free(symbol_Table[i]);
    symbol_Table[i] = NULL;
}
count = 0;
symbol **symbol_Table;
int max_size = SIZE; // declared elsewhere, e.g., in a header file

// Initialize the array
symbol_Table = malloc(max_size * sizeof(symbol*));

// When you need more space...
if (count == max_size) {
    max_size *= 2;
    symbol_Table = realloc(symbol_Table, max_size * sizeof(symbol*));
}
