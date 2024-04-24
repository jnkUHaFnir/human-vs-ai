void remove_leaf(tree *Y, int elem) {
    if (*Y == NULL) return;

    if ((*Y)->value < elem) {
        remove_leaf(&(*Y)->dx, elem);
    } else if ((*Y)->value > elem) {
        remove_leaf(&(*Y)->sx, elem);
    } else { // Node found
        if ((*Y)->sx == NULL && (*Y)->dx == NULL) {
            // It's a leaf node
            free(*Y);
            *Y = NULL;
        } else if ((*Y)->sx != NULL && (*Y)->dx == NULL) {
            // Node with only left child
            tree temp = *Y;
            *Y = (*Y)->sx;
            free(temp);
        } else if ((*Y)->sx == NULL && (*Y)->dx != NULL) {
            // Node with only right child
            tree temp = *Y;
            *Y = (*Y)->dx;
            free(temp);
        } else {
            printf("Can't eliminate that node with two children!\n");
        }
    }
    // No need to print in recursive function, it can be done after the operation
}

// Call remove_leaf like this:
printf("Which one do you want to destroy?  ");
scanf("%d", &elem);
remove_leaf(&Y, elem); // Pass the address of Y
// Instead of:
destroy_node(Y, elem);

// Call it like this:
destroy_node(&Y, elem);
