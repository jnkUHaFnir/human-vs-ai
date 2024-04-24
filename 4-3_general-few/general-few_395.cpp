void del_p(struct Node* current)
{
    if (current == NULL) {
        return;
    }

    struct Node* temp = current->next;

    if (temp == NULL) {
        // If the node to delete is the last node
        free(current);
        current = NULL;  // Optionally set the pointer to NULL
    }
    else {
        // If the node to delete is not the last node
        current->data = temp->data;
        current->next = temp->next;
        free(temp);
    }
}
