void del_p(struct Node* current)
{
    struct Node* temp;

    if (current == NULL) {
        return; // Handle case when node to be deleted is NULL
    }

    if (current->next != NULL) {
        temp = current->next;
        current->data = temp->data;
        current->next = temp->next;
        free(temp);
    } else {
        // If the current node is the last node in the list
        struct Node* prev = NULL;
        struct Node* temp = current;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        if (prev != NULL) {
            prev->next = NULL; // Update the previous node's next to NULL
        }

        free(temp);
    }
}
