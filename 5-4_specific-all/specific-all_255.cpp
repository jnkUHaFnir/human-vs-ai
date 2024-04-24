void del_p(struct Node* current)
{
    struct Node* temp;
    
    if (current == NULL) {
        return;
    }

    // Case 1: Node to be deleted is not the last node
    if (current->next != NULL)
    {
        temp = current->next;
        current->data = temp->data;
        current->next = temp->next;
        free(temp);
    }
    else // Case 2: Node to be deleted is the last node
    {
        struct Node* prev = NULL;
        struct Node* temp = current;
        
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        if (prev != NULL) {
            prev->next = NULL;
        } else {
            // If the last node is to be deleted and it is the only node in the list
            free(current);
            current = NULL;
        }
    }
}
