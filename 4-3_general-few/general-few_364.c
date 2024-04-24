void removeChild(node **trash){
    if((*trash)->left == NULL && (*trash)->right == NULL) { // No children
        free(*trash);
        *trash = NULL;
    }
    else if((*trash)->left != NULL && (*trash)->right != NULL) { // Both children
        // Find the node to replace 'trash'
        node *replacement = findReplacement((*trash)->right);
        
        // Copy the data from replacement to trash
        (*trash)->data = replacement->data;
        
        // Recursively remove the replacement node which has been moved to the 'trash' position
        removeChild(&replacement);
    }
    else if((*trash)->left == NULL) { // Only right child
        node *temp = *trash;
        *trash = (*trash)->right;
        free(temp);
    }
    else { // Only left child
        node *temp = *trash;
        *trash = (*trash)->left;
        free(temp);
    }
}

node* findReplacement(node *current) {
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}
