void insert(node **head, int x) {
    node *newNode = malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
``` 

This modified function first checks if the list is empty (head points to NULL), in which case it directly sets the head to the new node. Otherwise, it traverses the list to find the last node and appends the new node at the end.
