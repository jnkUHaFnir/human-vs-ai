struct symbol_table *symbol_table_create(void) {
    struct symbol_table *stt = malloc(sizeof(struct symbol_table));
    stt->count = 3; // Assuming you want to start with 3 elements
    stt->arr = malloc(sizeof(struct str_id*) * stt->count);

    for (int i = 0; i < stt->count; i++) {
        stt->arr[i] = malloc(sizeof(struct str_id));
        stt->arr[i]->s = malloc(sizeof(char) * MAX_SYMBOL_LENGTH); // Assuming MAX_SYMBOL_LENGTH is a defined constant
        stt->arr[i]->s[0] = '\0'; // Initialize the string to empty
        stt->arr[i]->id = i + 1; // Assigning an ID, you can change this as needed
    }

    return stt;
}
