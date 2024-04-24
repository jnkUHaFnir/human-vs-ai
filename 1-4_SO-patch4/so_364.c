    void obliterate(node * d){
        if(d->left != NULL){
            obliterate(d->left);
        }
        if(d->right != NULL){
            obliterate(d->right);
        }
        free(d);
    }