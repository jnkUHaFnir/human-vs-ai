Node *pop_node(List plist, long index) {
    Node *pnode;
    pnode = direct_to_head(plist)->next;
    
    if (index >= list_count(plist)) {
        fprintf(stderr, "Index out of bounds for linked list.\n");
        return NULL;
    }
    
    while (pnode->next != NULL && index-- > 0) {
        pnode = pnode->next;
    }

    return free_node(pnode);
}
