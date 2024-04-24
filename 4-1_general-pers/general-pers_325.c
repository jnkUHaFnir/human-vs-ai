for (i = 0; i < count; i++) {
    free(symbol_Table[i]);
}
if (count == SIZE) {
    SIZE *= 2; // Double the size (you can choose other strategies for resizing)
    symbol **temp = realloc(symbol_Table, SIZE * sizeof(symbol *));
    if (temp == NULL) {
        // Handle realloc failure
        // Optionally free existing memory before exit
        for (i = 0; i < count; i++) {
            free(symbol_Table[i]);
        }
        free(symbol_Table);
        // Clean up and exit
    } else {
        symbol_Table = temp;
    }
}
