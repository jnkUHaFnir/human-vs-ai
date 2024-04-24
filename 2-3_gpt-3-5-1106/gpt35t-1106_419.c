void destroy_node(tree Y, int elem) {
    if (Y == NULL) {
        return;
    }
    if (Y->value < elem) {
        destroy_node(Y->dx, elem);
    } else if (Y->value > elem) {
        destroy_node(Y->sx, elem);
    } else { // Node to be deleted is found
        if (Y->sx == NULL && Y->dx == NULL) {
            free(Y);
            Y = NULL;  // This doesn't reflect back in the parent node
        } else if (Y->sx != NULL && Y->dx == NULL) {
            // update parent's pointer to the left child
            // and then free the node
        } else if (Y->sx == NULL && Y->dx != NULL) {
            // update parent's pointer to the right child
            // and then free the node
        } else {
            printf("Can't eliminate that!\n");
        }
    }
    print_everything(Y);
}
