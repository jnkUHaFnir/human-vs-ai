void swap(struct student *pointer) {
    if (pointer == NULL || pointer->next == NULL) {
        // Not enough nodes to swap
        return;
    }

    struct student *pointer1, *pointer3, *pointer4;
    pointer1 = pointer->previous;
    pointer3 = pointer->next;
    pointer4 = pointer->next->next;

    if (pointer1 != NULL) {
        pointer1->next = pointer3;
    } else {
        // If pointer1 is NULL, then pointer is the first node
        first = pointer3;
    }
    if (pointer4 != NULL) {
        pointer4->previous = pointer;
    } else {
        // If pointer4 is NULL, then pointer3 is the last node
        last = pointer;
    }

    pointer3->previous = pointer1;
    pointer->next = pointer4;
    pointer->previous = pointer3;
    pointer3->next = pointer;
}
void sort(void) {
    int swapped;
    struct student *ptr;

    if (first == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr = first;
        while (ptr->next != NULL) {
            if (strcmp(ptr->Nachname, ptr->next->Nachname) > 0) {
                swap(ptr);
                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}
