struct product *add_product(struct product_list *start, const char *title, const char *code,
        int stock, double price) {
    struct product *newProduct = malloc(sizeof(struct product));
    newProduct->title = malloc(strlen(title) + 1);
    strcpy(newProduct->title, title);
    strncpy(newProduct->code, code, 7);
    newProduct->code[7] = '\0';
    newProduct->stock = stock;
    newProduct->price = price;
    newProduct->next = NULL;

    if (start->head == NULL) {
        start->head = newProduct;
    } else {
        struct product *current = start->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newProduct;
    }

    return newProduct;
}

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

int remove_product(struct product_list *start, const char *code) {
    struct product *current = start->head;
    struct product *prev = NULL;
    while (current != NULL) {
        if (!strcmp(current->code, code)) {
            if (prev == NULL) {
                start->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->title);
            free(current);
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}
