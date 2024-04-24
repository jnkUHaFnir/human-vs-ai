void removeChild(node **trash){
    if((*trash)->left == NULL && (*trash)->right == NULL) { //no parents
        free(*trash);
        *trash = NULL;
    }
    else if((*trash)->left == NULL && (*trash)->right != NULL) { //have mother
        (*trash)->right = NULL;
        free(*trash);
        *trash = NULL;
    }
    else if((*trash)->left != NULL && (*trash)->right == NULL) { //have father
        (*trash)->left = NULL;
        free(*trash);
        *trash = NULL;
    } else{  //have both
        removeChild(&(*trash)->left);
        removeChild(&(*trash)->right);
    }
}
