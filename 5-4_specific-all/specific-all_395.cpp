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
        free(temp);

        // This part is important to handle the case of deleting the last node properly
        struct Node* prev = NULL;
        struct Node* temp = current;
        while (temp != NULL && temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        
        if (prev != NULL)
        {
            prev->next = NULL;
        }
    }
}
