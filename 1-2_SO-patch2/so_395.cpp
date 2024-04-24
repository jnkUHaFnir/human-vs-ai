    void del_p(struct Node *head, struct Node *delete_node)
    {
        if (head != NULL)
        {
            struct Node *temp = head;
            if (head == delete_node) {
                head = head->next;
            } else {
                while (temp->next != delete_node) temp = temp->next;
                if (delete_node != NULL)
                {
                    temp->next = delete_node->next;
                }
            }
            free(temp);
        }
    }