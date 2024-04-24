Node *pop_node(List plist, long index){
    Node *pnode;
    pnode = direct_to_head(plist)->next;

    if(index > list_count(plist)){
        fprintf(stderr, "index out of linked list scope.\n");
        return NULL; // Return NULL to indicate out-of-scope
    }
    
    while (pnode->next != NULL && index-- > 0) {
        pnode = pnode->next;
    }

    return free_node(pnode);
}
