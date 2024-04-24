void destroy_node(tree *Y, int elem) {
    if ((*Y) == NULL) {
        return;
    }
    
    if ((*Y)->value < elem) {
        destroy_node(&((*Y)->dx), elem);
    } else if ((*Y)->value > elem) {
        destroy_node(&((*Y)->sx), elem);
    } else {
        if ((*Y)->sx == NULL && (*Y)->dx == NULL) {
            free(*Y);
            *Y = NULL;
        } else if ((*Y)->sx != NULL && (*Y)->dx == NULL) {
            tree temp = *Y;
            *Y = (*Y)->sx;
            free(temp);
        } else if ((*Y)->sx == NULL && (*Y)->dx != NULL) {
            tree temp = *Y;
            *Y = (*Y)->dx;
            free(temp);
        } else {
            printf("Can't eliminate that!\n");
        }
    }
    print_everything(*Y);
}
tree Y = T;
printf("Which one you want to destroy?  ");
scanf("%d", &elem);
destroy_node(&Y, elem);
