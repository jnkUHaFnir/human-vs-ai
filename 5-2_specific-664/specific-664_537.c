Node* pop_node(List plist, long index) {
    Node *pnode = direct_to_head(plist)->next;
    
    if (index > list_count(plist)) {
        fprintf(stderr, "index out of linked list scope.\n");
        return NULL; // Return NULL to indicate out-of-scope
    }

    while (pnode != NULL && index-- > 0) {
        pnode = pnode->next;
    }

    if (pnode == NULL) {
        fprintf(stderr, "index out of linked list scope.\n");
        return NULL; // Return NULL if index is out of scope
    }

    return free_node(pnode);
}
