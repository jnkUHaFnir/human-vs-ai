void destroy_node(tree *Y, int elem) {
    tree current = *Y;
    tree parent = NULL;

    // Find the node to be deleted
    while (current != NULL && current->value != elem) {
        parent = current;
        if (current->value < elem)
            current = current->dx;
        else
            current = current->sx;
    }

    // If the node doesn't exist, return
    if (current == NULL)
        return;

    // If the node is a leaf, remove it from the tree
    if (current->sx == NULL && current->dx == NULL) {
        if (parent == NULL) {
            free(current);
            *Y = NULL; // Update the root of the tree
        } else if (parent->sx == current) {
            free(current);
            parent->sx = NULL;
        } else {
            free(current);
            parent->dx = NULL;
        }
    }
    // If the node has only one child, replace the node with its child
    else if (current->sx != NULL && current->dx == NULL) {
        current->value = current->sx->value;
        free(current->sx);
        current->sx = NULL;
    } else if (current->sx == NULL && current->dx != NULL) {
        current->value = current->dx->value;
        free(current->dx);
        current->dx = NULL;
    }
    // If the node has two children, you cannot delete it
    else {
        printf("Can't eliminate that!\n");
    }

    print_everything(*Y);
}
