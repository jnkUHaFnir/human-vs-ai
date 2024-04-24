void removeChild(node **root, node *trash) {
    node *parent = *root;

    if (parent == NULL) {
        return; // Check if parent node is NULL
    }

    if (parent->left == trash) {
        parent->left = NULL;
    } else if (parent->right == trash) {
        parent->right = NULL;
    }

    // Recursively delete child node
    if (trash->left != NULL) {
        removeChild(&(trash->left), trash->left);
    }
    if (trash->right != NULL) {
        removeChild(&(trash->right), trash->right);
    }

    free(trash);
}
