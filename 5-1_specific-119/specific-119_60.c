/* Add product */
struct product *add_product(struct product_list *start, const char *title, const char *code,
        int stock, double price) {
    // Create a new product node
    struct product *new_product = malloc(sizeof(struct product));
    new_product->title = malloc(strlen(title) + 1);
    strcpy(new_product->title, title);
    strncpy(new_product->code, code, 7);
    new_product->code[7] = '\0';  // Null-terminate the code
    new_product->stock = stock;
    new_product->price = price;
    new_product->next = NULL;

    // Handle case when the list is empty
    if (start->head == NULL) {
        start->head = new_product;
        return new_product;
    }

    struct product *current = start->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_product;
    return new_product;
}

/* Find product */
struct product *find_product(struct product_list *start, const char *code) {
    struct product *current = start->head;
    while (current != NULL){
        if (!strcmp(current->code, code)) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/* Remove Product */
int remove_product(struct product_list *start, const char *code) {
    struct product *current = start->head;
    struct product *prev = NULL;
    
    // Handle case where the node to be removed is the head
    if (current != NULL && !strcmp(current->code, code)) {
        start->head = current->next;
        free(current->title);
        free(current);
        return 1;
    }

    while(current != NULL){
        if(!strcmp(current->code, code)){
            prev->next = current->next;
            free(current->title);
            free(current);
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}

/* Delete list */
int delete_list(struct product_list *listhead) {
    struct product *current = listhead->head;
    struct product *next;
    
    while (current != NULL) {
        next = current->next;
        free(current->title);
        free(current);
        current = next;
    }
    
    listhead->head = NULL; // Reset the head after deleting all nodes
    return 1;
}
