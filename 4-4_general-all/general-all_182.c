void swap(struct student *node1, struct student *node2) {
    struct student *temp_prev = node1->previous;
    struct student *temp_next = node2->next;

    // Update adjacent nodes to link node1 and node2
    if (temp_prev != NULL) {
        temp_prev->next = node2;
    } else {
        first = node2; // Check if node1 is first node
    }
    if (temp_next != NULL) {
        temp_next->previous = node1;
    }

    node1->next = node2->next;
    node2->next = node1;

    node2->previous = temp_prev;
    node1->previous = node2;
}

void sort(void) {
    struct student *current;

    // Perform bubble sort on the linked list
    for (int i = 0; i < length_of_list - 1; i++) {
        current = first;
        while (current->next != NULL) {
            if (strcmp(current->Nachname, current->next->Nachname) > 0) {
                if (current == first) {
                    first = current->next;
                }
                swap(current, current->next);
            } else {
                current = current->next;
            }
        }
    }
}
