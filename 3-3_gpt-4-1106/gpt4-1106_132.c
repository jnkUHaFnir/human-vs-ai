void insert(node **head, int x) {
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL) {
        // Handle memory allocation failure if needed.
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    // check if the list is empty
    if (*head == NULL) {
        // The list is empty, the new node is the new head.
        *head = newNode;
    } else {
        // Find the last node in the list
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // temp now points to the last node
        temp->next = newNode;
    }
}
typedef struct node {
    int data;
    struct node *next;
} node;
