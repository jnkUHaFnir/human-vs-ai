void insert(node **head, int x) {
    node *newNode = malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;

    node *temp = *head;

    if (*head == NULL) {
        *head = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
