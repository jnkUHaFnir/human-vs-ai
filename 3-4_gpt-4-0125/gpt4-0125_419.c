tree destroy_node(tree Y, int elem) {
    if (Y == NULL) return NULL; // Base case: node not found

    // Search for the node to be deleted and recur down the tree
    if (elem < Y->value)
        Y->sx = destroy_node(Y->sx, elem);
    else if (elem > Y->value)
        Y->dx = destroy_node(Y->dx, elem);
    else {
        // Node with only one child or no child
        if (Y->sx == NULL) {
            tree temp = Y->dx;
            free(Y);
            return temp;
        }
        else if (Y->dx == NULL) {
            tree temp = Y->sx;
            free(Y);
            return temp;
        }
    }
    return Y; // Return the unchanged node pointer
}
Y = destroy_node(Y, elem);
