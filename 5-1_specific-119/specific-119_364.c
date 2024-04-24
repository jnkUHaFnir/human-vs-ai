void removeChild(node **trash){
    node *temp = *trash;
    
    if(temp->left == NULL && temp->right == NULL) {
        free(temp);
        *trash = NULL; // Update parent's pointer
    }
    else if(temp->left == NULL && temp->right != NULL) {
        *trash = temp->right; // Update parent's pointer
        removeChild(&temp); // Recursively delete the node
    }
    else if(temp->left != NULL && temp->right == NULL) {
        *trash = temp->left; // Update parent's pointer
        removeChild(&temp); // Recursively delete the node
    } else {
        // Find the in-order successor (or predecessor) to maintain the binary search tree properties
        node *successor = temp->right;
        while(successor->left != NULL) {
            successor = successor->left;
        }
        
        // Copy the data from the successor to the current node
        strcpy(temp->data, successor->data);

        // Recursively delete the successor node
        removeChild(&successor);
    }
}
