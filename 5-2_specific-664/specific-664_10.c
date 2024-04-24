void insert(node **head, int x) {
    node *newNode = malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
}
