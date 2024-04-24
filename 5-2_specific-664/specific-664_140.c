void insert(node **head, int x) {
    node *new = malloc(sizeof(node));
    if (new == NULL) {
        // Handle malloc failure
        return;
    }
    new->data = x;
    new->next = NULL;

    if (*head == NULL) {
        *head = new;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
}
