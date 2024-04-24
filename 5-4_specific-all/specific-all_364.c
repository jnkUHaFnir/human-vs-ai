void delete(node* root){
    char array[13];
    printf ("Please specify a name to delete\n");
    scanf("%s", array);
    node *parent = NULL;
    node **toDelete = findNode(root, array, &parent);

    if(toDelete == NULL) {
        printf("ERROR -- Node does not exist");
        return;
    }

    if((*toDelete)->left == NULL && (*toDelete)->right == NULL) { // No children
        if(parent != NULL) {
            if(parent->left == *toDelete) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        } else {
            root = NULL; // Deleting root node
        }
        free(*toDelete);
    } else if((*toDelete)->left != NULL && (*toDelete)->right != NULL) { // Two children
        // Find the inorder successor (smallest in the right subtree)
        node *successor = (*toDelete)->right;
        parent = *toDelete;
        while (successor->left != NULL) {
            parent = successor;
            successor = successor->left;
        }

        // Copy the data from the successor to the node to be deleted
        (*toDelete)->data = successor->data;

        // Delete the successor node
        if(parent == *toDelete) {
            parent->right = successor->right;
        } else {
            parent->left = successor->right;
        }
        free(successor);
    } else { // One child
        node *child = ((*toDelete)->left != NULL) ? (*toDelete)->left : (*toDelete)->right;
        
        if(parent != NULL) {
            if(parent->left == *toDelete) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            root = child; // Deleting root node
        }
        
        free(*toDelete);
    }

    *toDelete = NULL;
}
