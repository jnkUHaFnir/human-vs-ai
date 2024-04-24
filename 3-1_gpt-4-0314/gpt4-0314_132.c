void insert(node **head, int x) {
    node *new = malloc(sizeof(node));
    new->data = x;
    new->next = NULL;

    // If the list is empty, set the new node as the head
    if (*head == NULL) {
        *head = new;
        return;
    }

    node *temp = *head;
    // Traverse the list while the next node is not NULL
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}
