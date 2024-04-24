void destroy_node(tree Y, int elem) {
    if (Y == NULL) {
        return;
    }

    if (Y->value < elem) {
        destroy_node(Y->dx, elem);
    } else if (Y->value > elem) {
        destroy_node(Y->sx, elem);
    } else {
        if (Y->sx == NULL && Y->dx == NULL) {
            free(Y);
            // Update the parent's link to NULL
            // This depends on whether Y is the right or left child of the parent
            // You need to pass the parent node to this function or handle this in a different way
        } else if (Y->sx != NULL && Y->dx == NULL) {
            Y->value = (Y->sx)->value;
            free(Y->sx);
            Y->sx = NULL;
        } else if (Y->sx == NULL && Y->dx != NULL) {
            Y->value = (Y->dx)->value;
            free(Y->dx);
            Y->dx = NULL;
        } else {
            printf("Can't eliminate that!\n");
        }
    }
}

int main() {
    tree T = NULL; // Initialize the tree
    tree Y = NULL;
    int elem, tot, val;

    printf("How many nodes will your tree have?  ");
    scanf("%d", &tot);

    for (int i = 0; i < tot; i++) {
        printf("What is the %d° node?  ", (i + 1));
        scanf("%d", &val);
        T = insert_node(T, val); // Ensure to update T with the resulting tree
    }

    Y = T; // Assign the root tree to Y

    printf("Which one do you want to destroy?  ");
    scanf("%d", &elem);
    destroy_node(Y, elem);

    return 0;
}
