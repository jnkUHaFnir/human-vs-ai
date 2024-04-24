void insert(node **head, int x) {
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL) {
        // Handle memory allocation error
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    if (*head == NULL) {
        // If the list is empty, set the new node as the head
        *head = newNode;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
