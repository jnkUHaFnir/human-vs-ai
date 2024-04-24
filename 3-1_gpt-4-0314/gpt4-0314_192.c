for (int i = 0; i < SIZE; ++i) {
    symbol_Table[i] = NULL;
}
if (count == SIZE) {
    SIZE *= 2;
    symbol_Table = (symbol **)realloc(symbol_Table, SIZE * sizeof(symbol *));
}
