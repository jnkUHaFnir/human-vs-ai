void swap(struct student *pointer) {
    struct student *pointer1, *pointer2, *pointer3;

    if (pointer == NULL || pointer->next == NULL) {
        return; // no need to swap if there are less than 2 nodes
    }

    pointer1 = pointer->previous;
    pointer2 = pointer;
    pointer3 = pointer->next;

    if (pointer1 != NULL) {
        pointer1->next = pointer3;
    }
    if (pointer3 != NULL) {
        pointer3->previous = pointer1;
    }

    pointer2->previous = pointer3;
    pointer2->next = pointer3->next;
    pointer3->next = pointer2;

    if (pointer2->next != NULL) {
        pointer2->next->previous = pointer2;
    }
}
void sort(void) {
    int isSwapped;
    struct student *pointer;

    if (first == NULL) {
        return; // the list is empty
    }

    do {
        isSwapped = 0;
        pointer = first;
        
        while (pointer->next != NULL) {
            if (strcmp(pointer->Nachname, pointer->next->Nachname) > 0) {
                swap(pointer);
                isSwapped = 1;
            }
            pointer = pointer->next;
        }
    } while (isSwapped);
}
