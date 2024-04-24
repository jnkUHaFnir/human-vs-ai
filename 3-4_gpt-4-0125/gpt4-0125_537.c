#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    void *data;
    struct node *next,*prev;
} Node;

typedef Node *List;

// Assuming these functions are implemented elsewhere in your code.
long list_count(List plist);
void* free_node(Node* pnode); // Adjusted to return void* (the data), assuming freeing node internally.
Node* direct_to_head(List plist); // Function to direct to the head of the list.

Node* pop_node(List plist, long index){
    if(index >= list_count(plist)){ // assuming index is 0-based.
        fprintf(stderr, "Error: Index out of linked list scope.\n");
        return NULL;
    }

    Node *pnode = direct_to_head(plist);
    
    // Loop until the specified index is reached
    while (index-- > 0 && pnode != NULL) {
        pnode = pnode->next;
    }
    
    // If pnode is NULL at this point, something went wrong
    if (!pnode) {
        fprintf(stderr, "Unexpected error: Reached NULL node before expected index.\n");
        return NULL;
    }

    // Disconnecting the node from the list before returning it
    if (pnode->prev) {
        pnode->prev->next = pnode->next;
    }
    if (pnode->next) {
        pnode->next->prev = pnode->prev;
    }
    
    // Assuming free_node now just frees the node's internals but returns the data.
    void* data = free_node(pnode); // Adjust based on actual return type of free_node.
    
    // Optionally wrap the data back into a newly allocated Node if needed
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    return newNode; // Or just return pnode directly if you prefer to keep the original node structure.
}

// Please ensure the rest of the functionality like list_count, free_node, and direct_to_head 
// are correctly implemented as they are crucial for this function to work correctly.
