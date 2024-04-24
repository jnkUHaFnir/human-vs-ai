    Node *pop_node(List plist,long index){
    Node *pnode,*next,*prev;
    pnode=direct_to_head(plist)->next;
    if(index>list_count(plist) || index <0){
        fprintf(stderr, "index out of link list scope.");
        return NULL;
    }
    while (pnode->next!=NULL && index-->0) {
        pnode=pnode->next;
    }
    next=pnode->next;
    prev=pnode->prev;
    pnode->head=NULL;
    pnode->tail=NULL;
    next->prev=prev;
    prev->next=next;
    c_free(pnode);
    return pnode->data;
    }