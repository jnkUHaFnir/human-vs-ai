double removeLowestValue() {
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *ptr = head;
    double val = 0;
    
    if (head == NULL) {
        return -1; // Return an error value
    }
    
    double lowestValue = head->value;
    
    while (ptr != NULL) {
        if (ptr->value <= lowestValue) {
            lowestValue = ptr->value;
            temp = prev;
        }
        
        prev = ptr;
        ptr = ptr->next;
    }

    if (temp == NULL) {
        // The minimum value is at the head of the list
        val = head->value;
        head = head->next;
        free(temp);
    } else {
        // Removing the right-most instance of the lowest value
        val = temp->next->value;
        ptr = temp->next;
        temp->next = ptr->next;

        if (ptr == tail) {
            tail = temp;
        }

        free(ptr);
    }

    return val;
}
