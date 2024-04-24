    void del_p(struct Node **head, struct Node *delete_node)
    {
        if (head != NULL)
        {
            struct Node *temp = *head;
            if (temp != NULL) {
               if (temp == delete_node) {
                   *head = *head->next;
               } else {
                   while (temp->next != NULL && temp-next != delete_node) temp = temp->next;
                   if (delete_node != NULL)
                   {
                       temp->next = delete_node->next;
                   }
               }
               free(temp);
            }
        }
    }