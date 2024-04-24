void del_p(struct Node* current)
{
    struct Node* temp;

    if (current == NULL) {
        return;
    }

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
        struct Node* prev = NULL;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        if (prev != NULL) {
            prev->next = NULL;
        } else {
            // If there is only one node in the list
            free(temp);
            current = NULL;
            return;
        }
    }
}
