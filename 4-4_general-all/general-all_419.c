void destroy_node(tree *Y, int elem) {
    if (*Y == NULL) {
        printf("Node with value %d not found in the tree.\n", elem);
        return;
    }

    if ((*Y)->value < elem) {
        destroy_node(&((*Y)->dx), elem);
    } else if ((*Y)->value > elem) {
        destroy_node(&((*Y)->sx), elem);
    } else {
        if ((*Y)->sx == NULL && (*Y)->dx == NULL) {
            free(*Y);
            *Y = NULL; // Set the pointer in the parent node to NULL
        } else if ((*Y)->sx != NULL && (*Y)->dx == NULL) {
            // Handle case where node is connected only to the left child
            tree temp = *Y;
            *Y = (*Y)->sx;
            free(temp);
        } else if ((*Y)->sx == NULL && (*Y)->dx != NULL) {
            // Handle case where node is connected only to the right child
            tree temp = *Y;
            *Y = (*Y)->dx;
            free(temp);
        } else {
            printf("Can't eliminate node with value %d as it has two children.\n", elem);
        }
    }
}
tree Y = T;
printf("Which node do you want to destroy?  ");
scanf("%d", &elem);
destroy_node(&Y, elem);
tree insert_node(tree T, int val) {
    if (T == NULL) {
        T = (tree)malloc(sizeof(struct node));
        T->value = val;
        T->sx = NULL;
        T->dx = NULL;
    } else {
        if (val < T->value) {
            T->sx = insert_node(T->sx, val);
        } else {
            T->dx = insert_node(T->dx, val);
        }
    }
    return T;
}
