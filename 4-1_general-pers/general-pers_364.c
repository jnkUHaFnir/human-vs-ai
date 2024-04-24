struct node {
    char *data;
    struct node *left;
    struct node *right;
} *root;

void delete(node **root) {
    char array[13];
    node *toDelete;
    printf("Please specify a name to delete\n");
    scanf("%s", array);
    toDelete = scan(*root, array);
    if (toDelete == NULL) {
        printf("ERROR -- Node does not exist");
    } else {
        *root = removeChild(*root, toDelete);
    }
}

node* removeChild(node *root, node *toDelete) {
    if (root == NULL) {
        return root;
    }

    if (toDelete == NULL) {
        return root;
    }

    if (root == toDelete) {
        if (toDelete->left == NULL) {
            node *rightChild = toDelete->right;
            free(toDelete);
            return rightChild;
        } else if (toDelete->right == NULL) {
            node *leftChild = toDelete->left;
            free(toDelete);
            return leftChild;
        } else {
            // Node has two children
            node *minRight = findMin(toDelete->right);
            toDelete->data = minRight->data;
            toDelete->right = removeChild(toDelete->right, minRight);
        }
    } else if (toDelete->data < root->data) {
        root->left = removeChild(root->left, toDelete);
    } else {
        root->right = removeChild(root->right, toDelete);
    }

    return root;
}

node* findMin(node *node) {
    node = node->left;
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
