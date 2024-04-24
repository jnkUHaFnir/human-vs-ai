double removeLowestValue() {
    if (head == NULL) return -1; // Assuming negative values are not part of your list

    struct node *temp = NULL;
    struct node *ptr = head;
    struct node *toFree = NULL;
    
    double val = head->value;

    // Edge case: list contains only one element or no duplicates of head.
    if (head->next == NULL || head->value != head->next->value) {
        printf("The lowest value is unique or the list has only one element. No removal performed.\n");
        return val; // If the lowest value is unique or only one element exists, return its value immediately.
    }

    while (ptr->next != NULL) { // Traverse till the second last element.
        if (ptr->next->value == val) { // Found the lowest value.
            temp = ptr; // Keep track of the node before the right-most occurrence.
        }
        ptr = ptr->next;
    }

    // Below conditions handle the edge cases when the list has duplicates at the end or just a single non-duplicated value.
    if (temp == NULL) { // This means no duplicates were found after head, which should not happen due to your logic.
        printf("Unexpected case: No duplicates of the lowest value found beyond head.\n");
        return -1;
    }

    // The right-most occurrence of the lowest value is in ptr->next.
    toFree = temp->next;
    temp->next = temp->next->next; // Or simply, ptr->next to skip the node to be removed.
    free(toFree);

    // Update the tail if the removed node was the last node.
    if (temp->next == NULL) {
        tail = temp;
    }

    return val;
}
printf("%f", removeLowestValue());
