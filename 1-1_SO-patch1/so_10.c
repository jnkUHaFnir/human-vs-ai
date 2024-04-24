    void insert(node **head, int x) {
        node *new = malloc(sizeof(node));
        new->data = x;
        new->next = NULL;
        node **np = head;
        while (*np) {
            np = &(*np)->next;
        }
        *np = new;
    }