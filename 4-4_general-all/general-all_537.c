#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void *data;
    struct node *next, *prev, *head, *tail;
} Node;

typedef Node *List;

Node* free_node(Node *node) {
    // Perform necessary cleanup
    free(node);
    return NULL;
}

Node* pop_node(List plist, long index) {
    Node *pnode = plist->next;
    
    if (index >= list_count(plist)) {
        fprintf(stderr, "Index out of linked list scope.\n");
        return NULL; // Return a special value (NULL) to indicate out of scope
    }

    while (pnode != NULL && index > 0) {
        pnode = pnode->next;
        index--;
    }
    
    if (pnode == NULL) {
        fprintf(stderr, "Index out of linked list scope.\n");
        return NULL; // Return NULL if index is still out of scope after traversal
    }

    // Process the node
    return free_node(pnode);
}

