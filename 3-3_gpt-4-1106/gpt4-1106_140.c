void insert(node **head, int x) {
    node *new = malloc(sizeof(node));
    if (new == NULL) {
        // Handle the error, for example, by returning from the function
        return;
    }
    new->data = x;
    new->next = NULL;

    // If the list is empty, the new node is now the head
    if (*head == NULL) {
        *head = new;
        return;
    }

    // Otherwise, find the end of the list
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Append the new node to the list
    temp->next = new;
}
