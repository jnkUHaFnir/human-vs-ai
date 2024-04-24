void insert(node **head, int x) {
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL) {
        // Handle malloc failure
        return;
    }
    
    newNode->data = x;
    newNode->next = NULL;

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
        return;
    }

    node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
