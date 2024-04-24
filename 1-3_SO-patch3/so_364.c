    // free a node and all its children.
    void free_node(node * d){
        
        if(d->left != NULL){
            obliterate(d->left);
            // Free the other data attached to the node...
        }
        if(d->right != NULL){
            obliterate(d->right);
            // ...left as an exercise to the reader.
        }
        free(d);
    }
    // obliterate a node and the reference you're giving me.
    void obliterate(node ** n){
        free_node(*n);
        *n = NULL;
    }