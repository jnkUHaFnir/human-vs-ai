Node* pop_node(List plist, long index){
    Node *pnode;
    pnode = direct_to_head(plist)->next;

    if(index > list_count(plist)){
        fprintf(stderr, "index out of link list scope.");
        return NULL;
    }

    while (pnode->next != NULL && index-- > 0) {
        pnode = pnode->next;
    }

    return free_node(pnode);
}
