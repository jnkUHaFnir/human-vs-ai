void destroy_node(tree parent, tree current, int elem) {
    if (current == NULL) {
        printf("Element not found in the tree\n");
        return;
    }

    if (current->value < elem) {
        destroy_node(current, current->dx, elem);
    } else if (current->value > elem) {
        destroy_node(current, current->sx, elem);
    } else {
        if (current->sx == NULL && current->dx == NULL) {
            if (parent->sx == current) {
                parent->sx = NULL;
            } else {
                parent->dx = NULL;
            }
            free(current);
        } else if (current->sx != NULL && current->dx == NULL) {
            current->value = (current->sx)->value;
            free(current->sx);
            current->sx = NULL;
        } else if (current->sx == NULL && current->dx != NULL) {
            current->value = (current->dx)->value;
            free(current->dx);
            current->dx = NULL;
        } else {
            printf("Can't eliminate that!\n");
        }
        print_everything(parent);
    }
}
tree Y = T;
printf("Which one you want to destroy?  ");
scanf("%d", &elem);
destroy_node(NULL, Y, elem);  // Pass NULL as parent since it is the root
