void insert(node **head, int x) {
    node *new_node = malloc(sizeof(node));
    new_node->data = x;
    new_node->next = NULL;

    if (*head == NULL) {
        // If the list is empty, insert the new node at the beginning
        *head = new_node;
    } else {
        // Otherwise, find the last node in the list
        node *temp = *head;

        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        // Insert new node at the end
        temp->next = new_node;
    }
}
