void swap(struct student *pointer1, struct student *pointer2) {
    if (pointer1 == NULL || pointer2 == NULL) {
        return; // handle invalid pointers
    }
    
    if (pointer1->previous != NULL) {
        pointer1->previous->next = pointer2;
    }
    
    if (pointer2->next != NULL) {
        pointer2->next->previous = pointer1;
    }
    
    if (pointer1->next == pointer2) {
        pointer1->previous = pointer2;
        pointer2->next = pointer1;
    } else {
        struct student *temp1 = pointer1->previous;
        struct student *temp2 = pointer2->next;
        
        pointer1->previous = pointer2;
        pointer2->next = pointer1;
        pointer2->previous = temp1;
        pointer1->next = temp2;
        
        if (temp1 != NULL) {
            temp1->next = pointer2;
        }
        
        if (temp2 != NULL) {
            temp2->previous = pointer1;
        }
    }
}
void sort(void) {
    int swapped;
    struct student *ptr1;
    struct student *lptr = NULL;
    
    if (first == NULL) {
        return; // empty list
    }
    
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
