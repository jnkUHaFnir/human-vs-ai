tree destroy_node(tree Y, int elem) {
    if (!Y) return NULL;

    if (Y->value < elem) {
        Y->dx = destroy_node(Y->dx, elem);
    }
    else if (Y->value > elem) {
        Y->sx = destroy_node(Y->sx, elem);
    }
    else { // Y->value == elem
        if (Y->sx == NULL && Y->dx == NULL) {
            free(Y);
            return NULL;
        }
        if (Y->sx != NULL && Y->dx == NULL) {
            tree left = Y->sx;
            free(Y);
            return left;
        }
        if (Y->sx == NULL && Y->dx != NULL) {
            tree right = Y->dx;
            free(Y);
            return right;
        }
        if (Y->sx != NULL && Y->dx != NULL)
            printf("Can't eliminate that!\n");
    }
    print_everything(Y);
    return Y;
}
tree Y = T;
printf("Which one you want to destroy?  ");
scanf("%d", &elem);
T = destroy_node(Y, elem);
