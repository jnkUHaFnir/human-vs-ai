struct product *add_product(struct product_list *start, const char *title, const char *code, int stock, double price) {
    struct product *current = start->head;

    while (current->next != NULL) {
        current = current->next;
    }

    if (current->title == NULL) {
        current->title = malloc(strlen(title) + 1);
        strcpy(current->title, title);
        strncpy(current->code, code, 7);
        current->code[7] = '\0'; // Ensure the code is null-terminated
        current->stock = stock;
        current->price = price;
    } else {
        current->next = malloc(sizeof(struct product));
        current = current->next;
        current->title = malloc(strlen(title) + 1);
        strcpy(current->title, title);
        strncpy(current->code, code, 7);
        current->code[7] = '\0'; // Ensure the code is null-terminated
        current->stock = stock;
        current->price = price;
        current->next = NULL;
    }

    return current;
}
