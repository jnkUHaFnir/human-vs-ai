void insert(node **head, int x) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return;
    }
    new_node->data = x;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
