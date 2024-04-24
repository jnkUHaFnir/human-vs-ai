void insert(node **head, int x) {
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL) {
        // Handle the memory allocation error if needed
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    // If the list is empty, insert the new node as the first node.
    if (*head == NULL) {
        *head = newNode;
    } else {
        // Find the last node of the list
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Append the new node to the end of the list
        temp->next = newNode;
    }
}
typedef struct node {
    int data;
    struct node *next;
} node;
