#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void *data;
    struct node *next, *prev, *head, *tail;
} Node;

typedef Node *List;

// Function to return the count of nodes in the linked list
int list_count(List plist) {
    // Implement your logic to count nodes here
    return 0; // Placeholder, implement your own logic
}

// Function to free memory of a node and return its data
void *free_node(Node *node) {
    // Implement your logic to free the node and return data
    void *data = node->data;
    free(node);
    return data;
}

Node *pop_node(List plist, long index) {
    Node *pnode;
    pnode = plist->next;
    int count = list_count(plist);

    if (index >= count || index < 0) {
        fprintf(stderr, "Index is out of linked list scope.\n");
        return NULL;
    }

    while (pnode != NULL && index > 0) {
        pnode = pnode->next;
        index--;
    }

    if (pnode == NULL) {
        fprintf(stderr, "Node not found at index %ld.\n", index);
        return NULL;
    }

    return free_node(pnode);
}
