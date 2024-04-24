struct product *add_product(struct product_list *start, const char *title, const char *code, int stock, double price) {

    struct product *current = start->head;
    
    // Reach end of list or the first 'null' product
    while(current->next != NULL && current->title != NULL) {
        current = current->next;
    }
    
    // Your original code
}
struct product *find_product(struct product_list *start, const char *code) {

    struct product *current = start->head;
    while(current != NULL){
        if (strcmp(current->code, code) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
int remove_product(struct product_list *start, const char *code) {

    struct product *current = start->head;
    struct product *previous=NULL;

    while(current!=NULL && strcmp(current->code, code)!=0){
        previous = current;
        current = current->next;
    }

    if(current==NULL) return 0;

    if(previous==NULL) start->head = current->next;
    else previous->next = current->next;

    free(current->title);
    free(current);

    return 1;
}
int delete_list(struct product_list *listhead) {
    struct product *current = listhead->head; 
    struct product *next = NULL;
    
    // Keep a reference to next before freeing
    while(current != NULL){
        next = current->next;
        free(current->title);
        free(current);
        current = next;
    }
    listhead->head = NULL;
    return 1;
}
