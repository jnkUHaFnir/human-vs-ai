void destroy_node(tree *Y, int elem) {
    if (*Y == NULL) {
        return;
    }

    if ((*Y)->value < elem) {
        destroy_node(&((*Y)->dx), elem);
    } else if ((*Y)->value > elem) {
        destroy_node(&((*Y)->sx), elem);
    } else { // Node to delete found
        if ((*Y)->sx == NULL && (*Y)->dx == NULL) {
            free(*Y);
            *Y = NULL; // Update parent's reference to this node
        } else {
            // Handle other cases where the node is connected
            // Code for replacement nodes goes here
        }
    }
}
tree T = NULL;
printf("How many nodes your tree will have? ");
scanf("%d", &tot);
for (int i = 0; i < tot; i++) {
    int val;
    printf("What is the %d° node? ", (i + 1));
    scanf("%d", &val);
    T = insert_node(T, val);
}

tree Y = T;
printf("Which one you want to destroy? ");
scanf("%d", &elem);
destroy_node(&Y, elem);
