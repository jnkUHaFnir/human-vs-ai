struct tuple_t *tuple_create2(int tuple_dim, char **tuple){
    struct tuple_t *t = (struct tuple_t *) malloc(sizeof(struct tuple_t));

    if(t == NULL)
        return NULL;

    t->tuple_dimension = tuple_dim;
    t->tuple = (char **) malloc(tuple_dim * sizeof(char *));

    if (t->tuple == NULL) {
        free(t);
        return NULL;
    }

    for (int i = 0; i < tuple_dim; i++) {
        t->tuple[i] = (char*)malloc(strlen(tuple[i]) + 1);
        strcpy(t->tuple[i], tuple[i]);
    }

    return t;
}
