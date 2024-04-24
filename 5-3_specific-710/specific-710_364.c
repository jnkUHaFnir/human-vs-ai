void removeChild(node **root, const char *name) {
    if (*root == NULL) {
        return; // Base case: empty tree
    }
    
    int cmp = strcmp(name, (*root)->data);
    if (cmp < 0) {
        removeChild(&(*root)->left, name);
    } else if (cmp > 0) {
        removeChild(&(*root)->right, name);
    } else { // Node to delete found
        if ((*root)->left == NULL) {
            node *temp = (*root)->right;
            free(*root);
            *root = temp;
        } else if ((*root)->right == NULL) {
            node *temp = (*root)->left;
            free(*root);
            *root = temp;
        } else {
            // Node has two children
            // Find the in-order successor (smallest node in the right subtree)
            node *temp = findMinNode((*root)->right);
            // Copy the in-order successor's data to this node
            (*root)->data = temp->data;
            // Delete the in-order successor
            removeChild(&(*root)->right, temp->data);
        }
    }
}

node* findMinNode(node* root) {
    node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
