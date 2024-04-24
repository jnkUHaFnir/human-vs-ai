void del_p(struct Node* current)
{
    struct Node* temp;
    if (current == NULL)
    {
        return; // The node is null, nothing to delete
    }
    if (current->next == NULL)
    {
        // It is the last node, we cannot delete it using this method.
        // You could set its value to an invalid state if possible.
        return;
    }
    
    // The current node is not the last one, so we can delete it.
    temp = current->next;
    current->data = temp->data;
    current->next = temp->next;
    free(temp);
}
int main()
{
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 4);
    push(&head, 6);
    push(&head, 8);
    print(head);
    // Attempt to delete a non-last node to see how the delete works
    del_p(head->next->next); // Delete the node with value 4
    cout << endl;
    print(head);
    return 0;
}
