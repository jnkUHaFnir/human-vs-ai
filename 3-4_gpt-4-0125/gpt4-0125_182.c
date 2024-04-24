void swap(struct student *node1) {
    struct student *node0 = node1->previous;
    struct student *node2 = node1->next;
    struct student *node3;

    // If there's only one node or node2 is NULL (i.e., node1 is the last node), we can't swap.
    if (node1 == NULL || node2 == NULL)
        return;

    // Adjust node3 which is after node2
    node3 = node2->next;

    // Swapping node1 and node2 assuming they are adjacent
    if (node0) // If node1 is not the first node
        node0->next = node2;
    node2->previous = node0;
    node2->next = node1;
    node1->previous = node2;
    node1->next = node3;
    if (node3) // If node2 is not the last node
        node3->previous = node1;

    // Handle special cases for first and last global pointers
    if (node1 == first)
        first = node2;
    if (node2 == last)
        last = node1;
}
void sort(void) {
    int swapped;
    struct student *ptr;
    struct student *lptr = NULL;

    if (first == NULL)
        return;

    do {
        swapped = 0;
        ptr = first;

        while (ptr->next != lptr) {
            if (strcmp(ptr->Nachname, ptr->next->Nachname) > 0) {
                swap(ptr);
                swapped = 1;
            } else {
                ptr = ptr->next;
            }
        }
        lptr = ptr;
    } while (swapped);
}
