void del_p(struct Node* head, struct Node* current)
{
    struct Node* temp;

    // Check if the node to delete is the head
    if (head == current) {
        head = current->next;
        free(current);
        return;
    }

    // Find the previous node to the node to be deleted
    struct Node* prev = head;
    while (prev->next != current) {
        prev = prev->next;
    }

    // Update the next pointer of the previous node
    prev->next = current->next;

    // Delete the current node
    free(current);
}

del_p(head, head->next->next->next);
