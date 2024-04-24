void destroy_node(tree *Y, int elem) {
    if ((*Y)->value < elem) {
        destroy_node(&((*Y)->dx), elem);
    } else if ((*Y)->value > elem) {
        destroy_node(&((*Y)->sx), elem);
    } else { 
        if ((*Y)->sx == NULL && (*Y)->dx == NULL) {
            free(*Y);
            *Y = NULL;
        } else if ((*Y)->sx != NULL && (*Y)->dx == NULL) {
            (*Y)->value = ((*Y)->sx)->value;
            free((*Y)->sx);
            (*Y)->sx = NULL;
        } else if ((*Y)->sx == NULL && (*Y)->dx != NULL) {
            (*Y)->value = ((*Y)->dx)->value;
            free((*Y)->dx);
            (*Y)->dx = NULL;
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
