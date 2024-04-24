void swap(struct student *node) {
    struct student *prevNode = node->previous;
    struct student *nextNode = node->next;
    
    // Update pointers around the node to be swapped
    if(prevNode != NULL) {
        prevNode->next = nextNode;
    }
    if(nextNode != NULL) {
        nextNode->previous = prevNode;
    }
    
    // Update pointers of the node to be swapped
    node->previous = prevNode->previous;
    node->next = prevNode;
    
    // Update pointers of the adjacent nodes
    if(prevNode->previous != NULL) {
        prevNode->previous->next = node;
    } else {
        first = node;
    }
    prevNode->previous = node;
}
