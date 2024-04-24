double removeLowestValue() {
    struct node *temp = NULL;
    struct node *ptr = head;
    double val = ptr->value;
    
    if (head == NULL) {
        return -1;
    }

    if (head == tail) {
        free(head);
        head = NULL;
        tail = NULL;
    } else {
        while (ptr->next != NULL && ptr->value == ptr->next->value) {
        /* Find the right-most instance of the lowest value */
            temp = ptr;
            ptr = ptr->next;
            val = ptr->value;
        }

        if (temp != NULL) {
            if (ptr == head) { // If the head needs to be removed
                head = head->next;
                free(ptr);
            } else {
                temp->next = ptr->next;
                free(ptr);
            }
        }
    }
    
    return val;
}
