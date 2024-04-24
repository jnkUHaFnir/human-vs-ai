    void del_p(struct Node *head)
    {
        if (head != NULL)
        {
            struct Node *temp = NULL;
            while (head->next->next != NULL) head = head->next;
            temp = head->next;
            free(temp);
            head->next = NULL;
        }
    }