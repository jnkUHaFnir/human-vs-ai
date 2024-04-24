void del_p(struct Node** head_ref, struct Node* current)
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
        struct Node* temp = *head_ref;
        
        if (temp == current) // If only one node
        {
            (*head_ref) = NULL;
            free(current);
            current = NULL;
        }
        else
        {
            while (temp->next != current)
            {
                temp = temp->next;
            }
            
            temp->next = NULL;
            free(current);
            current = NULL;
        }
    }
}
del_p(&head, head->next->next->next);
``` 

With this change, the last node should be deleted correctly without causing any infinite loops or issues with garbage values.
