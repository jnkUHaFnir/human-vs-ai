typedef struct Node {
    unsigned long long A;
    char *B;
    struct Node *next;
} Node;
#define TABLE_SIZE 18446744073709551616   // Maximum possible A value

Node *hashTable[TABLE_SIZE] = {NULL};
void set(unsigned long long A, char *B) {
    // Create a new node and populate its fields
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->A = A;
    newNode->B = B;
    newNode->next = NULL;

    // Calculate the hash value for A
    unsigned long long hashValue = A % TABLE_SIZE;

    // Insert the new node into the hash table
    if (hashTable[hashValue] == NULL) {
        // No collision, directly insert the new node
        hashTable[hashValue] = newNode;
    } else {
        // Collision occurred, append the new node at the end of the linked list
        Node *current = hashTable[hashValue];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
char* get(unsigned long long A) {
    // Calculate the hash value for A
    unsigned long long hashValue = A % TABLE_SIZE;

    // Traverse the linked list at the hash index to find the node with the matching A value
    Node *current = hashTable[hashValue];
    while (current != NULL) {
        if (current->A == A) {
            return current->B;   // Return the B value of the matching node
        }
        current = current->next;
    }

    return NULL;   // No matching node found
}
