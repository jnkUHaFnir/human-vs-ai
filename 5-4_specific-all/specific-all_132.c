void insert(node **head, int x) {
    node *new_node = malloc(sizeof(node));
    new_node->data = x;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}
