void del_p(struct Node* current)
{
    struct Node* temp;
    if (current->next != NULL)
    {
        temp = current->next;
        current->data = temp->data;
        current->next = temp->next;
        free(temp);
    }
    else
    {
        struct Node* temp = current;
        current = NULL;
        // Special case if the head is being deleted
        // You need to update the head pointer in this case
        if (temp == head) {
            head = NULL;
        } else {
            // Find the previous node to the current node
            struct Node* prev = head;
            while (prev->next != current) {
                prev = prev->next;
            }
            prev->next = NULL;
        }
        free(temp);
    }
}
