void _destroy_node(tree *Y, int elem) {
    if ((*Y)->value < elem)
        _destroy_node(&((*Y)->dx), elem);
    else if ((*Y)->value > elem)
        _destroy_node(&((*Y)->sx), elem);
    else {
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
        } else 
            printf("Can't eliminate that!\n");
    }
}

void destroy_node(tree Y, int elem) {
    _destroy_node(&Y, elem);
}
    free(*Y);
    *Y = NULL;
    if (!*Y)
        return;  // The item isn't in our tree.
