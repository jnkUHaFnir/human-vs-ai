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
        } else if ((*Y)->sx == NULL) {
            tree temp = *Y;
            *Y = (*Y)->dx;
            free(temp);
        } else if ((*Y)->dx == NULL) {
            tree temp = *Y;
            *Y = (*Y)->sx;
            free(temp);
        } else {
            printf("Can't eliminate that!\n");
        }
        // No need to set the child pointers to NULL here
    }
    // Do not print the tree here, do it after you have made all removals
}

int main() {
    tree T = NULL;
    int tot, val;
    
    printf("How many nodes should the tree have? ");
    scanf("%d", &tot);
    
    for (int i = 0; i < tot; i++) {
        printf("Enter the value of node %d: ", (i + 1));
        scanf("%d", &val);
        T = insert_node(T, val);
    }

    int elem;
    printf("Which node do you want to destroy? ");
    scanf("%d", &elem);
    
    destroy_node(&T, elem);
    print_everything(T); // Print the tree after all removals have been performed
    
    return 0;
}
