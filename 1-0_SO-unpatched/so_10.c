    void insert(node **head, int x) {
        node *new_node = malloc(sizeof(node));
        new_node->data = x;
        new_node->next = NULL;
        node **np = head;
        while (*np) {
            np = &(*np)->next;
        }
        *np = new_node;
    }