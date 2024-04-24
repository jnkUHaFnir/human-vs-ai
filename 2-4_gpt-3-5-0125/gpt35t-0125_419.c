tree destroy_node(tree Y, int elem) {
    if (Y == NULL) {
        return NULL; // Base case: if the tree is empty
    }

    if (Y->value < elem)
        Y->dx = destroy_node(Y->dx, elem);
    else if (Y->value > elem)
        Y->sx = destroy_node(Y->sx, elem);
    else { 
        if (Y->sx == NULL && Y->dx == NULL) {
            free(Y);
            return NULL;
        }
        if (Y->sx != NULL && Y->dx == NULL) {
            tree temp = Y->sx;
            free(Y);
            return temp;
        }
        if (Y->sx == NULL && Y->dx != NULL) {
            tree temp = Y->dx;
            free(Y);
            return temp;
        }
        if (Y->sx != NULL && Y->dx != NULL)
            printf("Can't eliminate that!\n");
    }
    return Y;
}
tree Y = T;
printf("Which one you want to destroy?  ");
scanf("%d", &elem);
Y = destroy_node(Y, elem);
print_everything(Y);
