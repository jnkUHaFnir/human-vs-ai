#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void *data;
    struct node *next, *prev, *head, *tail;
} Node;

typedef Node *List;

Node *pop_node(List plist, long index) {
    Node *pnode;
    pnode = plist->next;
    int count = 0;

    while (pnode != NULL && index > count) {
        pnode = pnode->next;
        count++;
    }

    if (count < index) {
        fprintf(stderr, "Index out of linked list scope.\n");
        return NULL;
    }

    // Implement your free_node function as needed
    // free_node(pnode);

    return pnode;
}
