int *entityIndices = NULL;
int capacity = 10; // Start with some capacity
int size = 0; // Tracks the number of entities added

entityIndices = (int *)malloc(capacity * sizeof(int));

// When you need to add an entity:
if (size >= capacity) {
    // We need more space
    capacity *= 2; // Double the capacity
    int *newPointer = (int *)realloc(entityIndices, capacity * sizeof(int));
    if (newPointer == NULL) {
        // Handle allocation failure
    } else {
        entityIndices = newPointer;
    }
}

// Add the entity value
entityIndices[size++] = newEntityIndex;

// At the end, remember to free the memory
free(entityIndices);
typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

// Function to add an entity to list
void addEntity(Node **headRef, Node **tailRef, int entityIndex) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        // Handle allocation failure
        return;
    }
    newNode->value = entityIndex;
    newNode->next = NULL;

    if (*tailRef) { // If list is not empty
        (*tailRef)->next = newNode;
        *tailRef = newNode;
    } else { // If list is empty
        *headRef = newNode;
        *tailRef = newNode;
    }
}

// Function to free the list
void freeList(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

// To add an entity:
addEntity(&head, &tail, newEntityIndex);
// To free the list:
freeList(head);
