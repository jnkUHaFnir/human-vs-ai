    // free a node and all its children.
    void free_node(node * n){
        
        // free the left child (if any)
        if(n->left != NULL){
            free_node_data(n->left);
            obliterate(n->left);
            
        }
        
        // free the right child (if any)
        if(n->right != NULL){
            free_node_data(n->right);
            obliterate(n->right);
        }
        // actually free the thing.
        free(n);
    }
    // obliterate a node and the reference you're giving me.
    void free(node ** n){
        free_node(*n);
        *n = NULL;
    }