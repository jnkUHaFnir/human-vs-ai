void insert(node **head, int x) {
    node *new = malloc(sizeof(node));
    new->data = x;
    new->next = NULL;

    if (*head == NULL) {
        *head = new; // If the list is empty, new node becomes the head
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
}
