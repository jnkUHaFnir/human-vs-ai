symbol **new_table = realloc(symbol_Table, new_size * sizeof(symbol *));
if (new_table == NULL) {
    // realloc failed, handle the error
    return;
}
symbol_Table = new_table;
