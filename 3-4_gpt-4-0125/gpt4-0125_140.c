void insert(node **head, int x) {
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL) {
        // Handle memory allocation failure.
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    // If the list is empty, make the new node the head.
    if (*head == NULL) {
        *head = newNode;
    } else {
        node *temp = *head;
        
        // Traverse the list to find the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        // At this point, temp points to the last node in the list.
        temp->next = newNode;
    }
}
