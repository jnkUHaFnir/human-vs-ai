struct tuple_t *tuple_create2(int tuple_dim, char **tuple){
    struct tuple_t *t = (struct tuple_t *) malloc(sizeof(struct tuple_t));

    if(t == NULL)
        return NULL;

    t->tuple_dimension = tuple_dim;
    t->tuple = malloc(tuple_dim * sizeof(char*));

    if(t->tuple == NULL){
        free(t);
        return NULL;
    }

    for(int i = 0; i < tuple_dim; i++){
        t->tuple[i] = strdup(tuple[i]);
        if(t->tuple[i] == NULL){
            for(int j = 0; j < i; j++){
                free(t->tuple[j]);
            }
            free(t->tuple);
            free(t);
            return NULL;
        }
    }

    return t;
}
