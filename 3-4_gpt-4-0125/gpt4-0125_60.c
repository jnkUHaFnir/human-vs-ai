while(start->head->next != NULL){
    start->head = start->head->next;
}
void init_list(struct product_list *list) {
    list->head = NULL;
}
struct product *add_product(struct product_list *start, const char *title, const char *code, int stock, double price) {
    struct product *new_node = malloc(sizeof(struct product));
    new_node->title = malloc(strlen(title) + 1);
    strcpy(new_node->title, title);
    strncpy(new_node->code, code, 7);
    new_node->code[7] = '\0'; // Make sure the string is NULL-terminated
    new_node->stock = stock;
    new_node->price = price;
    new_node->next = NULL;

    if (start->head == NULL) {
        // List is empty, new node becomes head
        start->head = new_node;
    } else {
        // Traverse to the end of the list and add the new node
        struct product *current = start->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    return new_node;
}
struct product *find_product(struct product_list *start, const char *code) {
    struct product *current = start->head;
    while (current != NULL) {
        if (strcmp(current->code, code) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
int remove_product(struct product_list *start, const char *code) {
    struct product *current = start->head;
    struct product *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->code, code) == 0) {
            if (prev == NULL) {
                // Removing the head
                start->head = current->next;
            } else {
                // Removing a non-head node
                prev->next = current->next;
            }
            free(current->title);
            free(current);
            return 1; // Node removed
        }
        prev = current;
        current = current->next;
    }
    return 0; // Node not found
}
int delete_list(struct product_list *list) {
    struct product *current = list->head;
    while (current != NULL) {
        struct product *next = current->next;
        free(current->title);
        free(current);
        current = next;
    }
    list->head = NULL; // Reset head after deletion
    return 1;
}
