void insert(node **head, int x) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
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
