void del_p(struct Node* current)
{
    struct Node* temp = current;
    struct Node* prev = NULL;

    // Traverse to the second last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        // If there is only one node in the list
        free(current);
        current = NULL;
    } else {
        // Delete the last node
        prev->next = NULL;
        free(temp);
    }
}
