    void del_p(struct Node *head, struct Node *delete)
    {
        if (head != NULL)
        {
            struct Node *temp = NULL;
            while (head->next->next != delete) head = head->next;
            temp = head->next;
            if (temp == NULL)
            {
                head->next = NULL;
            } else {
                head->next = temp->next;
            }
            free(temp);
        }
    }