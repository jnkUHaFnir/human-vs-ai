Node *pop_node(List plist, long index) {
    Node *pnode = direct_to_head(plist)->next;
  
    if (index >= list_count(plist) || index < 0) {
        fprintf(stderr, "Index out of linked list scope.\n");
        return NULL; // Return NULL to indicate error
    }
    
    while (pnode->next != NULL && index-- > 0) {
        pnode = pnode->next;
    }

    if (pnode == NULL) {
        fprintf(stderr, "Failed to find node at specified index.\n");
        return NULL; // Return NULL to indicate error
    }

    return free_node(pnode);
}
