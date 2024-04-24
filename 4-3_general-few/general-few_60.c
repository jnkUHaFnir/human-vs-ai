struct product *add_product(struct product_list *start, const char *title, const char *code,
        int stock, double price) {
    struct product *temp = start->head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->title == NULL){
        temp->title = malloc(strlen(title) + 1);
        strcpy(temp->title, title);
        strncpy(temp->code, code, 7);
        temp->code[7] = 0;
        temp->stock = stock;
        temp->price = price;
    }else{
        temp->next = malloc(sizeof(struct product));
        temp = temp->next;
        temp->title = malloc(strlen(title) + 1);
        strcpy(temp->title, title);
        strncpy(temp->code, code, 7);
        temp->code[7] = 0;
        temp->stock = stock;
        temp->price = price;
    }
    return temp;
}
