void insert(node **head, int x) {
    node *new = malloc(sizeof(node));
    if (new == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    new->data = x;
    new->next = NULL;

    if (*head == NULL) {
        *head = new;
        return;
    }

    node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}
