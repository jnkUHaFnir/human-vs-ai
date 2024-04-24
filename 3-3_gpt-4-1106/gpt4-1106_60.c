/* Add product */
struct product *add_product(struct product_list *start, const char *title, const char *code,
        int stock, double price) {
    // Create a new node
    struct product *new_node = malloc(sizeof(struct product));
    new_node->title = malloc(strlen(title) + 1);
    strcpy(new_node->title, title);
    strncpy(new_node->code, code, 7);
    new_node->code[7] = '\0';
    new_node->stock = stock;
    new_node->price = price;
    new_node->next = NULL;

    // If list is empty, make the new node the head
    if (start->head == NULL || start->head->title == NULL) {
        start->head = new_node;
    } else {
        // Otherwise, find the end of the list and add the new node
        struct product *current = start->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    return new_node;
}

/* Find product */
struct product *find_product(struct product_list *start, const char *code) {
    struct product *current = start->head;
    while (current != NULL) {
        if (!strcmp(current->code, code)) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/* Remove product */
int remove_product(struct product_list *start, const char *code) {
    struct product *current = start->head;
    struct product *previous = NULL;
    while (current != NULL) {
        if (!strcmp(current->code, code)) {
            if (previous == NULL) { // Head needs to be removed
                start->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->title);
            free(current);
            return 1;
        }
        previous = current;
        current = current->next;
    }
    return 0;
}

/* Delete list */
int delete_list(struct product_list *listhead) {
    struct product *current = listhead->head;
    while (current != NULL){
        struct product *next = current->next;
        free(current->title);
        free(current);
        current = next;
    }
    listhead->head = NULL; // Reset the head pointer to NULL
    return 1;
}
