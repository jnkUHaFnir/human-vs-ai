struct symbol_table *symbol_table_create(void) {
    struct symbol_table *stt = malloc(sizeof(struct symbol_table));
    stt->count = 3; // Assuming you want 3 elements initially
    stt->arr = malloc(sizeof(struct str_id*) * stt->count);

    // Allocate memory for each struct str_id element in the arr array
    for (int i = 0; i < stt->count; i++) {
        stt->arr[i] = malloc(sizeof(struct str_id));
        stt->arr[i]->s = malloc(20); // Allocate memory for the string 's' (adjust size as needed)
    }

    // Initialize the symbol table elements
    char* symbols[] = {"sym1", "sym2", "sym3"};
    for (int i = 0; i < stt->count; i++) {
        strcpy(stt->arr[i]->s, symbols[i]);
        stt->arr[i]->id = i + 1; // Assuming IDs are 1-indexed
    }

    return stt;
}
