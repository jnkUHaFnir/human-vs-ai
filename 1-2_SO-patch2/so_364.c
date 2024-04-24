    // free a node and all its children.
    void free_node(node * n){
        
        if(n->left != NULL){
            free_node_data(n->left);
            obliterate(n->left);
            
        }
        if(n->right != NULL){
            free_node_data(n->right);
            obliterate(n->right);
        }
        
        // Dept. of redundancy department made me do this
        n->left = NULL;
        n->right = NULL;
        free(n);
    }
    // obliterate a node and the reference you're giving me.
    void obliterate(node ** n){
        free_node(*n);
        *n = NULL;
    }