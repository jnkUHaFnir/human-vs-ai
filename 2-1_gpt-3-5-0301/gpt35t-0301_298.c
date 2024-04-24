typedef struct node {
    int data;           // Data to be stored
    struct node *next;  // Pointer to next element in the list
} Node;
Node *head = NULL;
Node *newNode = (Node*)malloc(sizeof(Node));
newNode->data = entityIndex;
newNode->next = head;
head = newNode;
Node *current = head;
while (current != NULL) {
    // Do something with current->data
    current = current->next;
}
Node *current = head;
while (current != NULL) {
    Node *next = current->next;
    free(current);
    current = next;
}
head = NULL;
