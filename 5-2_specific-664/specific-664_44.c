#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tuple_t {
    int tuple_dimension; 
    char **tuple;        
};

struct tuple_t *tuple_create2(int tuple_dim, char **tuple){
    struct tuple_t *t = (struct tuple_t *) malloc(sizeof(struct tuple_t));

    if(t == NULL)
        return NULL;

    t->tuple_dimension = tuple_dim;
    t->tuple = (char **) malloc(tuple_dim * sizeof(char *));

    if(t->tuple == NULL){
        free(t);
        return NULL;
    }

    int i;
    for(i = 0; i < tuple_dim; i++){
        t->tuple[i] = (char *) malloc(strlen(tuple[i]) + 1); // +1 for '\0' termination
        strcpy(t->tuple[i], tuple[i]);
    }

    return t;
}

void tuple_destroy(struct tuple_t *t){
    if(t == NULL)
        return;

    int i;
    for(i = 0; i < t->tuple_dimension; i++){
        free(t->tuple[i]);
    }

    free(t->tuple);
    free(t);
}

int testRemoveMeio() {
    int result, i;
    struct list_t *list = list_create();

    char *tdata[3] = {"   ", "2014", "Fixe!"};
    struct tuple_t *t = tuple_create2(3, tdata);
    struct tuple_t *tdups[4];

    if(t == NULL){
        return -1; // Memory allocation failed
    }

    sprintf(t->tuple[0], "abc");
    tdups[0] = tuple_dup(t);
    entries[0] = entry_create(tdups[0]);
    list_add(list, entries[0]);

    //extra code similar to above

    tuple_destroy(t); // Free memory allocated for tuple t
    return 0;
}
