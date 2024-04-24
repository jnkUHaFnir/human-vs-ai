void del_p(struct Node* current)
{
    struct Node* temp;
    if (current == NULL || current->next == NULL) {
        // Handle if the node to delete is NULL or if it is the last node
        return;
    }
    
    temp = current->next;
    current->data = temp->data;
    current->next = temp->next;
    free(temp);
}
