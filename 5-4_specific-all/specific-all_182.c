void swap(struct student *node1, struct student *node2) {
    struct student *temp_previous, *temp_next;
    
    // Update the previous and next pointers of the nodes surrounding node1
    if (node1->previous != NULL) {
        node1->previous->next = node2;
    }
    if (node2->next != NULL) {
        node2->next->previous = node1;
    }
    
    // Swap previous pointers of node1 and node2
    temp_previous = node1->previous;
    node1->previous = node2->previous;
    node2->previous = temp_previous;
    
    // Swap next pointers of node1 and node2
    temp_next = node1->next;
    node1->next = node2->next;
    node2->next = temp_next;
    
    // Update surrounding nodes to point to the correct nodes after swapping
    if (node1->previous == NULL) {
        first = node2;
    } else if (node2->previous == NULL) {
        first = node1;
    }
    
    if (node1->next == NULL) {
        last = node2;
    } else if (node2->next == NULL) {
        last = node1;
    }
}
void sort(void) {
    int swapped;
    struct student *ptr1;
    struct student *lptr = NULL;

    // Checking for empty list
    if (first == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = first;

        while (ptr1->next != lptr) {
            if (strcmp(ptr1->Nachname, ptr1->next->Nachname) > 0) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
