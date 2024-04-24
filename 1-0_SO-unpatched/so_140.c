    void insert(node **head, int x) {
        node *new_node = malloc(sizeof(node));
        new_node->data = x;
        new_node->next = NULL;
        node *temp = *head;
        if (temp == NULL) {
            *head = new_node;
        } else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }