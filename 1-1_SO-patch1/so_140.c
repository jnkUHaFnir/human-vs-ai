    void insert(node **head, int x) {
        node *new = malloc(sizeof(node));
        new->data = x;
        new->next = NULL;
        node *temp = *head;
        if (temp == NULL) {
            *head = new;
        } else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new;
        }
    }