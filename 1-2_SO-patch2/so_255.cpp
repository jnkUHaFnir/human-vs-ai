    void del_p(struct Node *head)
    {
        if (head != NULL)
        {
            struct Node *temp = head;
            while (temp->next != NULL) temp = temp->next;
            free(temp);
        }
    }