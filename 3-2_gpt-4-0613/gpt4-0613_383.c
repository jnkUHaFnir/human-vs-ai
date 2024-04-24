symbol **temp = (symbol **)realloc(symbol_Table, (SIZE*2) * sizeof(symbol *));
if (temp == NULL) {
    // handle error, insufficient memory
} else {
    symbol_Table = temp;
}
