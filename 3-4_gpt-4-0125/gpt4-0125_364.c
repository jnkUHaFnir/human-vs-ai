// Assuming the existence of a function to find the in-order successor
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Utility function to delete a node in a binary tree
struct node* deleteNode(struct node* root, char* key) {
    if (root == NULL) return root;

    if (strcmp(key, root->data) < 0)
        root->left = deleteNode(root->left, key);
    else if (strcmp(key, root->data) > 0)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
