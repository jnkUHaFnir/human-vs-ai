    tree destroy_node(tree Y, int elem) {
        tree res = Y;
        if (Y != NULL) {
            if (Y->value < elem) {
                Y->dx = destroy_node(Y->dx, elem);
            } else
            if (Y->value > elem) {
                Y->sx = destroy_node(Y->sx, elem);
            } else {
            if (Y->sx == NULL && Y->dx == NULL) {
                res = NULL;
                free(Y);
            } else
            if (Y->dx == NULL) {
                res = Y->sx;
                free(Y);
            } else
            if (Y->sx == NULL) {
                res = Y->dx;
                free(Y);
            } else {
                printf("Can't eliminate that!\n");
            }
        }
        return res;
    }